#pragma once

//////////////
// INCLUDES //
//////////////
#include "BaseContext.h"

#include "Map.h"
#include "CharacterContainer.h"
#include "PlayerMobile.h"

////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////
class ContextWorld : public BaseContext
{
	Map m_Map;
	CharacterContainer m_Characters;

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
	std::unique_ptr<T>& Get(Point2D<unsigned int> point)
	{
		static_assert(false, "Invalid Type");
	}

	template<>
	std::unique_ptr<MapTile>& Get<MapTile>(Point2D<unsigned int> point)
	{
		return m_Map.Get(point);
	}
	
	template<>
	std::unique_ptr<Mobile>& Get<Mobile>(Point2D<unsigned int> point)
	{
		return m_Characters.Get(point);
	}
};