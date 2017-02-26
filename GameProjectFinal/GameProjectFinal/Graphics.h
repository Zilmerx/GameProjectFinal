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
		m_Context->Shutdown();

		m_Context = new ContextType{ this };
		if (!m_Context)
		{
			return false;
		}

		// Initialize the model object.
		m_Context->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext());

		m_Camera->SetPosition(0.0f, 0.0f);
		m_Camera->SetHandlers(m_Context->GetInputManager());

		return true;
	}

private:

	Direct3D* m_Direct3D;
	Camera* m_Camera;
	BaseContext* m_Context;
	ColorShader* m_ColorShader;
	TextureShader* m_TextureShader;
};