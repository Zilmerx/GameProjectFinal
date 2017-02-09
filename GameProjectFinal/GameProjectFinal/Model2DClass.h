#pragma once
////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _MODEL2DCLASS_H_
#define _MODEL2DCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"
#include "Position.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: ModelClass
////////////////////////////////////////////////////////////////////////////////
class Model2DClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	Model2DClass();
	Model2DClass(const Model2DClass&);
	~Model2DClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*);
	void Shutdown();
	void Render(ID3D11Device*, ID3D11DeviceContext*);

	int GetIndexCount();

	TextureClass* GetTexture();
	ID3D11ShaderResourceView* GetTextureView();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void ReleaseTexture();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass* m_Texture;
};

#endif