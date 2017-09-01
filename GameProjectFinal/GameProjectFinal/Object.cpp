
#include "Object.h"
#include "InputManager.h"

Object::Object(Model2D* model) :
	Position{ 0,0,0 },
	Rotation{ 0,0,0 },
	Scale{ 1,1,1 },
	m_ModelManager{ new StaticModelManager(model) }
{
}

Object::Object(const Object& other)
{
	m_ModelManager = other.m_ModelManager;
}

Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Shutdown()
{
}

void Object::Render(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_ModelManager->Render(device, deviceContext);
}

Model2D* Object::GetModel() const
{
	return m_ModelManager->getCurrentModel();
}