#pragma once

//////////////
// INCLUDES //
//////////////
#include "Direct3D.h"
#include "Camera.h"
#include "ColorShader.h"
#include "TextureShader.h"
#include "Position.h"


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

	void SetCameraPosition(Position pos)
	{
		Point3D<float> pos2 = pos.GetPosition();
		m_Camera->SetPosition(pos2.x, pos2.y);
	}

private:

	Direct3D* m_Direct3D;
	Camera* m_Camera;
	ColorShader* m_ColorShader;
	TextureShader* m_TextureShader;
};