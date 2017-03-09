#pragma once

//////////////
// INCLUDES //
//////////////
#include "Model2D.h"

#include "Position.h"
#include "Rotation.h"
#include "Scale.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Object : public Position, public Rotation, public Scale
{

	Model2D* m_Model;

public:

	Object(Model2D* model);
	Object(const Object& other);
	~Object();

	void Initialize();
	void Shutdown();
	void Render(ID3D11Device*, ID3D11DeviceContext*);

	Model2D* GetModel() const;
};