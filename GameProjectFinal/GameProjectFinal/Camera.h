#pragma once

//////////////
// INCLUDES //
//////////////
#include <directxmath.h>
using namespace DirectX;

#include "Aligned.h"


////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Camera : public Aligned_
{
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	void SetPosition(float, float, float);
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