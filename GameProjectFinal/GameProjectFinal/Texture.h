#pragma once


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>


////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Texture
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

	Texture();
	Texture(const Texture&);
	~Texture();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*, D3D11_USAGE);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();
	D3D11_USAGE GetCurrUsage();

	unsigned short GetWidth() const;
	unsigned short GetHeight() const;

private:

	bool LoadTarga(char*, int&, int&, unsigned char*&);

private:

	D3D11_USAGE m_usage;
	TargaHeader m_targaHeader;
	ID3D11Texture2D* m_texture;
	ID3D11ShaderResourceView* m_textureView;

};