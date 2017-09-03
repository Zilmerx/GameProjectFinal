
#include <assert.h>

#include "Object.h"
#include "InputManager.h"

Object::Object(MOVETYPE mode, Model2D* model)
{
	if (mode == MOVETYPE::STATIC)
	{
		m_ModelManager = new StaticModelManager(model);
	}
	else if (mode == MOVETYPE::DYNAMIC)
	{
		m_ModelManager = new AnimatedModelManager(model);
	}
	else
	{
		assert(false);
	}
}

Object::Object(const Object& other)
{
	m_ModelManager = (BaseModelManager*)(other.getBaseModelAnimation()->clone());
}

Object::~Object()
{
	delete m_ModelManager;
}

void Object::Initialize()
{
}

void Object::Shutdown()
{
}

Model2D* Object::Render(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	return m_ModelManager->Render(device, deviceContext);
}

BaseModelManager* Object::getBaseModelAnimation() const
{
	return m_ModelManager;
}