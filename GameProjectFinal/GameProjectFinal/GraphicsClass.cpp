////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"
#include "ScreenSize.h"
#include "InputManager.h"


GraphicsClass::GraphicsClass()
{
	m_Direct3D = nullptr;
	m_Camera = nullptr;
	m_World = nullptr;
	m_ColorShader = nullptr;
	m_TextureShader = nullptr;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}


	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -28.0f); // -28.0f corresponds à 

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::ARR_UP>(
			[this](SHORT)
			{
				m_Camera->SetPosition(0.0f, 1.0f, -1.0f);
			}
		)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::ARR_DOWN>(
			[this](SHORT)
			{
				m_Camera->SetPosition(0.0f, -1.0f, -1.0f);
			}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::ARR_LEFT>(
			[this](SHORT)
			{
				m_Camera->SetPosition(-1.0f, 0.0f, -1.0f);
			}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::ARR_RIGHT>(
			[this](SHORT)
			{
				m_Camera->SetPosition(1.0f, 0.0f, -1.0f);
			}
			)
	);

	// Create the model object.
	m_World = new WorldClass;
	if (!m_World)
	{
		return false;
	}



	// Initialize the model object.
	m_World->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext());

	// Create the color shader object.
	m_ColorShader = new ColorShaderClass;
	if (!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_TextureShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
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

	// Release the model object.
	if (m_World)
	{
		m_World->Shutdown();
		delete m_World;
		m_World = 0;
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


bool GraphicsClass::Frame()
{
	bool result;

	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render()
{
	bool result;


	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	XMMATRIX worldMatrix = m_Direct3D->GetWorldMatrix();
	XMMATRIX viewMatrix = m_Camera->GetViewMatrix();
	XMMATRIX projectionMatrix = m_Direct3D->GetProjectionMatrix();

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	for (auto& ptr : m_World->m_Map)
	{
		ptr->Render(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext());

		Model2DClass* model = ptr->GetModel();

		XMMATRIX rot = ptr->GetRotationMatrix();
		XMMATRIX tra = ptr->GetTranslationMatrix();
		XMMATRIX sca = ptr->GetScaleMatrix();

		XMMATRIX objectMat = rot * sca * tra;
		//XMMATRIX objectMat = rot * tra * sca;

		// Render the model using the texture shader.
		result = m_TextureShader->Render(m_Direct3D->GetDeviceContext(), model->GetIndexCount(), worldMatrix * objectMat, viewMatrix, projectionMatrix, model->GetTexture()->GetTexture());
		if (!result)
		{
			return false;
		}
	}

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}
