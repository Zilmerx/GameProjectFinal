#pragma once

//////////////
// INCLUDES //
//////////////
#include "Model2D.h"
#include "StaticModelManager.h"
#include "AnimatedModelManager.h"
#include "StaticDynamicEnum.h"

#include "Position.h"
#include "Rotation.h"
#include "Scale.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class Object : public Position, public Rotation, public Scale
{

	BaseModelManager* m_ModelManager;

public:

	Object(MOVETYPE mode, Model2D* model);
	Object(const Object& other);
	~Object();

	void Initialize();
	void Shutdown();
	Model2D* Render(ID3D11Device*, ID3D11DeviceContext*);
	BaseModelManager* getBaseModelAnimation() const;
};