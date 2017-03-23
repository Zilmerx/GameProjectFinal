
#include "Position.h"

Position::Position()
{
	SetPosition(0.0f, 0.0f, 0.0f);
}

Position::Position(float XPos, float YPos, float ZPos)
{
	SetPosition(XPos, YPos, ZPos);
}

void Position::SetPosition(float XPos, float YPos, float ZPos)
{
	x = XPos;
	y = YPos;
	z = ZPos;
}

void Position::SetGridPosition(int XPos, int YPos, int ZPos)
{
	x = static_cast<float>(XPos);
	y = static_cast<float>(YPos);
	z = static_cast<float>(ZPos);
}

Point3D<float> Position::GetPosition() const
{
	return *this;
}

Point3D<int> Position::GetGridPosition() const
{
	return { (int)x, (int)y, (int)z };
}

DirectX::XMMATRIX Position::GetTranslationMatrix() const
{
	return XMMatrixTranslation(x, y, z);
}