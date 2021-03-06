////////////////////////////////////////////////////////////////////////////////
// Filename: Model2DClass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "Model2D.h"
#include "InputManager.h"
#include "Settings.h"
#include "Direct3D.h"


Model2D::Model2D(D3D11_USAGE usage) :
	m_Usage{ usage }
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_Texture = 0;
}


Model2D::Model2D(const Model2D& other)
{
	m_vertexBuffer = other.m_vertexBuffer;
	m_indexBuffer = other.m_indexBuffer;
	m_vertexCount = other.m_vertexCount;
	m_indexCount = other.m_indexCount;
	m_Texture = other.m_Texture;
}


Model2D::~Model2D()
{
}


bool Model2D::Initialize(std::string textureFilename)
{
	bool result;


	// Initialize the vertex and index buffers.
	result = InitializeBuffers();
	if (!result)
	{
		return false;
	}

	// Load the texture for this model.
	result = LoadTexture(textureFilename, m_Usage);
	if (!result)
	{
		return false;
	}
	m_Name = textureFilename;

	return true;
}


void Model2D::Shutdown()
{
	// Release the model texture.
	ReleaseTexture();

	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	return;
}


void Model2D::Render()
{
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	ID3D11DeviceContext* deviceContext = Globals::get().direct3d->GetDeviceContext();

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}


int Model2D::GetIndexCount() const
{
	return m_indexCount;
}

std::string Model2D::GetName() const
{
	return m_Name;
}

Texture* Model2D::GetTexture() const
{
	return m_Texture;
}

ID3D11ShaderResourceView* Model2D::GetTextureView() const
{
	return m_Texture->GetTexture();
}

bool Model2D::InitializeBuffers()
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	ID3D11Device* device;
	
	
	device = Globals::get().direct3d->GetDevice();

	// Set the number of vertices in the vertex array.
	m_vertexCount = 4;

	// Set the number of indices in the index array.
	m_indexCount = 6;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	// Load the vertex array with data.
	vertices[0].position = XMFLOAT3(-0.5f, -0.5f, 0.0f);  // Bottom left.
	vertices[0].texture = XMFLOAT2(0.0f, 1.0f);

	vertices[1].position = XMFLOAT3(-0.5f, +0.5f, 0.0f);  // Top left.
	vertices[1].texture = XMFLOAT2(0.0f, 0.0f);

	vertices[2].position = XMFLOAT3(+0.5f, +0.5f, 0.0f);  // top right.
	vertices[2].texture = XMFLOAT2(1.0f, 0.0f);

	vertices[3].position = XMFLOAT3(+0.5f, -0.5f, 0.0f);  // Bottom right.
	vertices[3].texture = XMFLOAT2(1.0f, 1.0f);

	// Load the index array with data.
	indices[0] = 0;  // Bottom left.
	indices[1] = 1;  // Top left.
	indices[2] = 2;  // top right.

	indices[3] = 0;  // Bottom left.
	indices[4] = 2;  // Top right.
	indices[5] = 3;  // Bottom right.

					 // Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = m_Usage;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = m_Usage;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}


void Model2D::ShutdownBuffers()
{
	// Release the index buffer.
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}


bool Model2D::LoadTexture(std::string filename, D3D11_USAGE usage)
{
	bool result;


	// Create the texture object.
	m_Texture = new Texture;
	if (!m_Texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_Texture->Initialize(filename, usage);
	if (!result)
	{
		return false;
	}

	return true;
}


void Model2D::ReleaseTexture()
{
	// Release the texture object.
	if (m_Texture)
	{
		m_Texture->Shutdown();
		delete m_Texture;
		m_Texture = 0;
	}

	return;
}