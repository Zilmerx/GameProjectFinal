#pragma once

//////////////
// INCLUDES //
//////////////
#include "Direct3D.h"
#include "Camera.h"
#include "ColorShader.h"
#include "TextureShader.h"
#include "Position.h"

class Object;
class BaseContext;


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
		Globals::get().context = m_Context;

		m_Camera->SetHandlers(m_Context->GetInputManager());

		return true;
	}

	void SetCameraPosition(Position pos)
	{
		Point3D<float> pos2 = pos.GetPosition();
		m_Camera->SetPosition(pos2.x, pos2.y);
	}

private:

	Direct3D* m_Direct3D;
	Camera* m_Camera;
	BaseContext* m_Context;
	ColorShader* m_ColorShader;
	TextureShader* m_TextureShader;
};