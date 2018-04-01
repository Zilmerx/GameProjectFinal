
#include <fstream>
#include <stdio.h>

#include "ARGBColor.h"
#include "Settings.h"
#include "Direct3D.h"

#include "Texture.h"

Texture::Texture()
{
	m_usage = D3D11_USAGE_DEFAULT;
	m_targaHeader;
	m_texture = nullptr;
	m_textureView = nullptr;
}


Texture::Texture(const Texture& other)
{
	m_usage = other.m_usage;
	m_targaHeader = other.m_targaHeader;
	m_texture = other.m_texture;
	m_textureView = other.m_textureView;
}


Texture::~Texture()
{
}

bool Texture::Initialize(std::string filename, D3D11_USAGE usage)
{
	m_usage = usage;

	bool result;
	int height, width;
	D3D11_TEXTURE2D_DESC textureDesc;
	HRESULT hResult;
	unsigned int rowPitch;
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;

	device = Globals::get().direct3d->GetDevice();
	deviceContext = Globals::get().direct3d->GetDeviceContext();

	unsigned char* targaData = nullptr;

	// Load the targa image data into memory.
	result = LoadTarga(filename, height, width, targaData);
	if (!result)
	{
		return false;
	}

	// Setup the description of the texture.
	textureDesc.Height = height;
	textureDesc.Width = width;
	textureDesc.MipLevels = 0;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = m_usage;
	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS;

	// Create the empty texture.
	hResult = device->CreateTexture2D(&textureDesc, NULL, &m_texture);
	if (FAILED(hResult))
	{
		return false;
	}

	// Set the row pitch of the targa image data.
	rowPitch = (width * 4) * sizeof(unsigned char);

	// Copy the targa image data into the texture.
	deviceContext->UpdateSubresource(m_texture, 0, NULL, targaData, rowPitch, 0);

	// Setup the shader resource view description.
	srvDesc.Format = textureDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = 4294967295U;

	// Create the shader resource view for the texture.
	hResult = device->CreateShaderResourceView(m_texture, &srvDesc, &m_textureView);
	if (FAILED(hResult))
	{
		return false;
	}

	// Generate mipmaps for this texture.
	deviceContext->GenerateMips(m_textureView);

	// Release the targa image data now that the image data has been loaded into the texture.
	delete[] targaData;
	targaData = 0;

	return true;
}

void Texture::Shutdown()
{
	// Release the texture view resource.
	if (m_textureView)
	{
		m_textureView->Release();
		m_textureView = 0;
	}

	// Release the texture.
	if (m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}

	return;
}

ID3D11ShaderResourceView* Texture::GetTexture()
{
	return m_textureView;
}

D3D11_USAGE Texture::GetCurrUsage()
{
	return m_usage;
}

unsigned short Texture::GetWidth() const
{
	return m_targaHeader.width;
}

unsigned short Texture::GetHeight() const
{
	return m_targaHeader.height;
}

bool Texture::LoadTarga(std::string filename, int& height, int& width, unsigned char*& targaData)
{
	std::ifstream input(filename, std::ios::in | std::ifstream::binary);

	// Read in the file header.
	input.read(reinterpret_cast<char*>(&m_targaHeader), sizeof(TargaHeader));

	// Check that it is 32 bit and not 24 bit.
	if (m_targaHeader.bpp != 32)
	{
		return false;
	}

	height = m_targaHeader.height;
	width = m_targaHeader.width;

	// Calculate the size of the 32 bit image data.
	unsigned int imageSize = width * height * 4;

	// Allocate memory for the targa destination data.
	targaData = new unsigned char[imageSize];

	// Read in the targa image data.
	input.read(reinterpret_cast<char*>(targaData), imageSize);

	// Initialize the index into the targa destination data array.
	int index = 0;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// Temporary to switch from BGRA to RGBA.
			ARGBColor temp;

			temp.blue	= targaData[index + 0];
			temp.green	= targaData[index + 1];
			temp.red	= targaData[index + 2];
			temp.alpha	= targaData[index + 3];

			targaData[index + 0] = temp.red;
			targaData[index + 1] = temp.green;
			targaData[index + 2] = temp.blue;
			targaData[index + 3] = temp.alpha;

			index += 4;
		}
	}

	return true;
}