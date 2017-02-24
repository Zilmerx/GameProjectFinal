
#include "Object.h"
#include "InputManager.h"

Object::Object(Model2D* model) :
	m_Position{ 0,0,0 },
	m_Rotation{ 0,0,0 },
	m_Scale{ 1,1,1 },
	m_Model{ model }
{
}

Object::Object(const Object& other)
{
	m_Position = other.m_Position;
	m_Rotation = other.m_Rotation;
	m_Scale = other.m_Scale;

	m_Model = other.m_Model;
}

Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Shutdown()
{
	m_Model->Shutdown();
}

void Object::Render(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	m_Model->Render(device, deviceContext);
}

XMMATRIX Object::GetTranslationMatrix() const
{
	return XMMatrixTranslation(
		m_Position.x,
		m_Position.y,
		m_Position.z);
}

XMMATRIX Object::GetRotationMatrix() const
{
	return XMMatrixRotationRollPitchYaw(
		m_Rotation.x,
		m_Rotation.y,
		m_Rotation.z);
}

XMMATRIX Object::GetScaleMatrix() const
{
	return XMMatrixScaling(
		m_Scale.x,
		m_Scale.y,
		m_Scale.z);
}

Model2D* Object::GetModel() const
{
	return m_Model;
}

void Object::SetSize(float XScale, float YScale)
{
	m_Scale.x = XScale;
	m_Scale.y = YScale;
}

void Object::SetPosition(int XPos, int YPos, int ZPos)
{
	m_Position.x = static_cast<float>(XPos);
	m_Position.y = static_cast<float>(YPos);
	m_Position.z = static_cast<float>(ZPos);
}

void Object::SetRotation(float x, float y, float z)
{
	m_Rotation.x = x;
	m_Rotation.y = y;
	m_Rotation.z = z;
}

Point3D<float> Object::GetSize() const
{
	return m_Scale;
}

Point3D<float> Object::GetRotation() const
{
	return m_Rotation;
}

Point3D<float> Object::GetPosition() const
{
	return m_Position;
}