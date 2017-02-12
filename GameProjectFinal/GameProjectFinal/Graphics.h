#pragma once

//////////////
// INCLUDES //
//////////////
#include "Direct3D.h"
#include "Camera.h"
#include "World.h"
#include "ColorShader.h"
#include "TextureShader.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&);
	~Graphics();

	bool Initialize(HWND);
	void Shutdown();
	bool Render();

private:

	Direct3D* m_Direct3D;
	Camera* m_Camera;
	World* m_World;
	ColorShader* m_ColorShader;
	TextureShader* m_TextureShader;
};