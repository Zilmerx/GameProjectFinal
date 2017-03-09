////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "Camera.h"
#include "Settings.h"

Camera::Camera()
{
	m_position = { 0.0f, 0.0f, 0.0f };
	m_rotation = { 0.0f, 0.0f, 0.0f };
}


Camera::Camera(const Camera&)
{
}


Camera::~Camera()
{
}

void Camera::SetHandlers(InputManager* manager)
{
	manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_W>(
		[this](SHORT)
	{
		SetPositionY(m_position.y += 0.1);
	}
	));

	manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_S>(
		[this](SHORT)
	{
		SetPositionY(m_position.y -= 0.1);
	}
	));

	manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_D>(
		[this](SHORT)
	{
		SetPositionX(m_position.x += 0.1);
	}
	));

	manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_A>(
		[this](SHORT)
	{
		SetPositionX(m_position.x -= 0.1);
	}
	));

	manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_T>(
		[this](SHORT)
	{
		SetPositionZ(m_position.z /= 1.1f);
	}
	));

	manager->AddHandler(InputEventHandler::Gen_DefaultHandler<Keys::KEY_G>(
		[this](SHORT)
	{
		SetPositionZ(m_position.z *= 1.1f);
	}
	));

}

void Camera::SetPosition(float x, float y, float z)
{
	m_position = { x,y,z };
	m_Dirty = true;
	return;
}

void Camera::SetPositionX(float x)
{
	m_position.x = x;
	m_Dirty = true;
}

void Camera::SetPositionY(float y)
{
	m_position.y = y;
	m_Dirty = true;
}

void Camera::SetPositionZ(float z)
{
	m_position.z = z;
	m_Dirty = true;
}


void Camera::SetRotation(float x, float y, float z)
{
	m_rotation = { x,y,z };
	m_Dirty = true;
	return;
}

void Camera::SetRotationX(float x)
{
	m_rotation.x = x;
}
void Camera::SetRotationY(float y)
{
	m_rotation.y = y;
}
void Camera::SetRotationZ(float z)
{
	m_rotation.z = z;
}

XMFLOAT3 Camera::GetPosition() const
{
	return m_position;
}


XMFLOAT3 Camera::GetRotation() const
{
	return m_rotation;
}

void Camera::Render()
{
	if(m_Dirty)
	{
		m_Dirty = false;

		XMFLOAT3 up, lookAt;
		XMVECTOR upVector, positionVector, lookAtVector;
		float yaw, pitch, roll;
		XMMATRIX rotationMatrix;


		// Setup the vector that points upwards.
		up.x = 0.0f;
		up.y = 1.0f;
		up.z = 0.0f;

		// Load it into a XMVECTOR structure.
		upVector = XMLoadFloat3(&up);

		// Load it into a XMVECTOR structure.
		positionVector = XMLoadFloat3(&GetPosition());

		// Setup where the camera is looking by default.
		lookAt.x = 0.0f;
		lookAt.y = 0.0f;
		lookAt.z = 1.0f;

		// Load it into a XMVECTOR structure.
		lookAtVector = XMLoadFloat3(&lookAt);

		// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
		pitch = m_rotation.x * ONE_DEGREE;
		yaw = m_rotation.y * ONE_DEGREE;
		roll = m_rotation.z * ONE_DEGREE;

		// Create the rotation matrix from the yaw, pitch, and roll values.
		rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

		// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
		lookAtVector = XMVector3TransformCoord(lookAtVector, rotationMatrix);
		upVector = XMVector3TransformCoord(upVector, rotationMatrix);

		// Translate the rotated camera position to the location of the viewer.
		lookAtVector = XMVectorAdd(positionVector, lookAtVector);

		// Finally create the view matrix from the three updated vectors.
		m_viewMatrix = XMMatrixLookAtLH(positionVector, lookAtVector, upVector);
	}

	return;
}

XMMATRIX Camera::GetViewMatrix() const
{
	return m_viewMatrix;
}