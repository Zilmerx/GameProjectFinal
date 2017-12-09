#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"

#include "Map.h"
#include "PlayerMobile.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextWorld : public BaseContext
{
	Map m_Map;
	std::vector<std::unique_ptr<Mobile>> m_Characters;

public:

	ContextWorld(Graphics* parent);

	~ContextWorld();

	void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

	virtual void Render(Graphics& gfx) override;

	virtual void Shutdown() override;

	Map& GetMap()
	{
		return m_Map;
	}

	template<class T>
	std::unique_ptr<T>& Get(Point2D<size_t> point)
	{
		static_assert(false, "Invalid Type");
	}

	template<>
	std::unique_ptr<MapTile>& Get<MapTile>(Point2D<size_t> point)
	{
		return m_Map.Get(point);
	}
	/*
	template<>
	Object* Get<Object>(Point2D<size_t> point)
	{

	}*/
};