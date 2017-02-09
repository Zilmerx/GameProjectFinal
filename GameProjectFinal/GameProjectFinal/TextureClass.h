////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTURECLASS_H_
#define _TEXTURECLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <stdio.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: TextureClass
////////////////////////////////////////////////////////////////////////////////
class TextureClass
{
private:

	struct TargaHeader
	{
		unsigned char data1[12];
		unsigned short width;
		unsigned short height;
		unsigned char bpp;
		unsigned char data2;
	};

public:

	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*, D3D11_USAGE);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();
	D3D11_USAGE GetCurrUsage();

	unsigned short GetWidth()
	{
		return m_targaHeader.width;
	}
	unsigned short GetHeight()
	{
		return m_targaHeader.height;
	}

private:

	bool LoadTarga(char*, int&, int&);

private:

	D3D11_USAGE m_usage;
	unsigned char* m_targaData;
	TargaHeader m_targaHeader;
	ID3D11Texture2D* m_texture;
	ID3D11ShaderResourceView* m_textureView;

};


#endif