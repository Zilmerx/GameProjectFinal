
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

void Position::SetGridPosition(unsigned int XPos, unsigned int YPos, unsigned int ZPos)
{
	x = static_cast<float>(XPos);
	y = static_cast<float>(YPos);
	z = static_cast<float>(ZPos);
}

Point3D<float> Position::GetPosition() const
{
	return *this;
}

Point3D<unsigned int> Position::GetGridPosition() const
{
	return { (unsigned int)x, (unsigned int)y, (unsigned int)z };
}

DirectX::XMMATRIX Position::GetTranslationMatrix() const
{
	return XMMatrixTranslation(x, y, z);
}