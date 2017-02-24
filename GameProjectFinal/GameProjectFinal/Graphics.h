#pragma once

//////////////
// INCLUDES //
//////////////
#include "Direct3D.h"
#include "Camera.h"
#include "ContextWorld.h"
#include "ContextMenu.h"
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

	bool RenderObject(Object& obj);

	template<class ContextType>
	bool SwitchContext()
	{
		m_Context = new ContextType;
		if (!m_Context)
		{
			return false;
		}

		// Initialize the model object.
		m_Context->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext());

		return true;
	}

private:

	Direct3D* m_Direct3D;
	Camera* m_Camera;
	BaseContext* m_Context;
	ColorShader* m_ColorShader;
	TextureShader* m_TextureShader;
};