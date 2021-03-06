
#include "Debug.h"
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
		Debug::Assert(false, "Invalid MoveType");
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

Model2D* Object::Render()
{
	return m_ModelManager->Render();
}

BaseModelManager* Object::getBaseModelAnimation() const
{
	return m_ModelManager;
}