#pragma once

//////////////
// INCLUDES //
//////////////
#include <directxmath.h>
using namespace DirectX;

#include "InputManager.h"
#include "Aligned.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Camera : public Aligned
{
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	void SetHandlers(InputManager* manager);

	void SetPosition(float, float, float z = -28.0f);
	void SetPositionX(float);
	void SetPositionY(float);
	void SetPositionZ(float);

	void SetRotation(float, float, float);
	void SetRotationX(float);
	void SetRotationY(float);
	void SetRotationZ(float);

	XMFLOAT3 GetPosition() const;
	XMFLOAT3 GetRotation() const;

	void Render();
	XMMATRIX GetViewMatrix() const;

private:
	bool m_Dirty;
	XMFLOAT3 m_position;
	XMFLOAT3 m_rotation;
	XMMATRIX m_viewMatrix;
};