#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"

#include "Map.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextWorld : public BaseContext
{
	Map m_Map;
	std::vector<std::unique_ptr<Object>> m_Characters;

public:

	ContextWorld(Graphics* parent);

	~ContextWorld();

	void InitializeDef(ID3D11Device* device, ID3D11DeviceContext* deviceContext) override;

	virtual void Render(Graphics& gfx) override;

	virtual void Shutdown() override;

	template<class T>
	std::unique_ptr<T>& Get(Point2D<size_t> point)
	{
		static_assert(false, "BadType");
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