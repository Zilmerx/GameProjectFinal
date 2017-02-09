
#include "ObjectClass.h"
#include "InputManager.h"

ObjectClass::ObjectClass() :
	m_Position{ 0,0 },
	m_Rotation{ 0 },
	m_Scale{ 1,1 }
{
	m_Model = new Model2DClass();
}

ObjectClass::ObjectClass(const ObjectClass& other)
{
	m_Position = other.m_Position;
	m_Rotation = other.m_Rotation;
	m_Scale = other.m_Scale;

	m_Model = other.m_Model;
}

ObjectClass::~ObjectClass()
{
	delete m_Model;
}

bool ObjectClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename)
{
	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_W>(
			[this](SHORT)
	{
		m_Position.y += 0.01f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_S>(
			[this](SHORT)
	{
		m_Position.y -= 0.01f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_A>(
			[this](SHORT)
	{
		m_Position.x -= 0.01f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_D>(
			[this](SHORT)
	{
		m_Position.x += 0.01f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_E>(
			[this](SHORT)
	{
		m_Rotation += 0.1f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_Q>(
			[this](SHORT)
	{
		m_Rotation -= 0.1f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_T>(
			[this](SHORT)
	{
		m_Scale.x += 0.03f;
		m_Scale.y += 0.03f;
	}
			)
	);

	InputManager::get().AddHandler(
		InputEventHandler::Gen_DefaultHandler<Keys::KEY_G>(
			[this](SHORT)
	{
		m_Scale.x -= 0.1f;
		m_Scale.y -= 0.1f;
	}
			)
	);


	return m_Model->Initialize(device, deviceContext, filename);
}

void ObjectClass::Shutdown()
{
	m_Model->Shutdown();
}

void ObjectClass::Render(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_Model->Render(device, deviceContext);
}