////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "Graphics.h"

#include "ScreenSize.h"
#include "InputManager.h"
#include "Object.h"
#include "ContextMenu.h"
#include "Debug.h"
#include "World.h"


Graphics::Graphics()
{
	m_Direct3D = nullptr;
	m_Camera = nullptr;
	m_ColorShader = nullptr;
	m_TextureShader = nullptr;
}


Graphics::Graphics(const Graphics&)
{
}


Graphics::~Graphics()
{
}


bool Graphics::Initialize(HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	m_Direct3D = new Direct3D;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(hwnd);
	if (!result)
	{
		Debug::Crash("Could not initialize Direct3D");
		return false;
	}


	// Create the camera object.
	m_Camera = new Camera;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f);
	Globals::get().camera = m_Camera;

	// Create the color shader object.
	m_ColorShader = new ColorShader;
	if (!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		Debug::Crash("Could not initialize the color shader object.");
		return false;
	}

	// Create the texture shader object.
	m_TextureShader = new TextureShader;
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_TextureShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		Debug::Crash("Could not initialize the texture shader object.");
		return false;
	}

	Globals::get().graphics = this;

	return true;
}


void Graphics::Shutdown()
{

	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the color shader object.
	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}


bool Graphics::Render()
{
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Render the worllld.

	for (auto& obj : Globals::get().world->m_Map)
	{
		Model2D* model = obj->Render();
		
		// Get the world, view, and projection matrices from the camera and d3d objects.
		XMMATRIX worldMatrix = m_Direct3D->GetWorldMatrix();
		XMMATRIX viewMatrix = m_Camera->GetViewMatrix();
		XMMATRIX projectionMatrix = m_Direct3D->GetProjectionMatrix();
		
		XMMATRIX rot = obj->GetRotationMatrix();
		XMMATRIX tra = obj->GetTranslationMatrix();
		XMMATRIX sca = obj->GetScaleMatrix();

		XMMATRIX objectMat = rot * sca * tra;

		m_TextureShader->Render(m_Direct3D->GetDeviceContext(), model->GetIndexCount(), worldMatrix * objectMat, viewMatrix, projectionMatrix, model->GetTexture()->GetTexture());
	}

	for (auto& obj : Globals::get().world->m_Characters)
	{
		Model2D* model = obj->Render();

		// Get the world, view, and projection matrices from the camera and d3d objects.
		XMMATRIX worldMatrix = m_Direct3D->GetWorldMatrix();
		XMMATRIX viewMatrix = m_Camera->GetViewMatrix();
		XMMATRIX projectionMatrix = m_Direct3D->GetProjectionMatrix();

		XMMATRIX rot = obj->GetRotationMatrix();
		XMMATRIX tra = obj->GetTranslationMatrix();
		XMMATRIX sca = obj->GetScaleMatrix();

		XMMATRIX objectMat = rot * sca * tra;

		m_TextureShader->Render(m_Direct3D->GetDeviceContext(), model->GetIndexCount(), worldMatrix * objectMat, viewMatrix, projectionMatrix, model->GetTexture()->GetTexture());
	}

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}