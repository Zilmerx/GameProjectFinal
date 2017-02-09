#pragma once

//////////////
// INCLUDES //
//////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "WorldClass.h"
#include "colorshaderclass.h"
#include "textureshaderclass.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render();

private:

	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	WorldClass* m_World;
	ColorShaderClass* m_ColorShader;
	TextureShaderClass* m_TextureShader;
};