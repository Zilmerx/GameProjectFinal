#pragma once


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <directxmath.h>
#include <string>
using namespace DirectX;

#include "Texture.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Model2D
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	Model2D(D3D11_USAGE);
	Model2D(const Model2D&);
	~Model2D();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, std::string);
	void Shutdown();
	void Render(ID3D11Device*, ID3D11DeviceContext*);

	int GetIndexCount() const;
	std::string GetName() const;

	Texture* GetTexture() const;
	ID3D11ShaderResourceView* GetTextureView() const;

	bool operator==(const Model2D& rhs) { return this->m_Name == rhs.m_Name; }

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, std::string, D3D11_USAGE);
	void ReleaseTexture();

private:
	std::string m_Name;
	D3D11_USAGE m_Usage;
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	Texture* m_Texture;
};