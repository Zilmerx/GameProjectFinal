#pragma once

#include <vector>
#include <algorithm>
#include <math.h>

#include "Map.h"
#include "Direction.h"
#include "UnsignedAbs.h"

class AStarPathfinding
{

	struct PathTile : public Point2D<unsigned int>
	{
		double g;
		double h;
		double f() { return g + h; }

		double cost;
		Direction parentDirection;

		PathTile(MapTile* tile) :
			Point2D(tile->GetGridPosition()),
			cost{ tile->cost() },
			g{ std::numeric_limits<double>::infinity() },
			h{ 0.0 },
			parentDirection{}
		{
		}

		void ComputeH(const Point2D<unsigned int> end)
		{
			h = UnsignedAbs(x, end.x) + UnsignedAbs(y, end.y);
		}

		void SetParent(const Point2D<int> from)
		{
			parentDirection = Direction{ *this, from };
		}
	};

	Map* m_map;
	std::vector<PathTile> m_ArrayMap;

	unsigned int mapWidth;
	unsigned int mapHeight;

	std::vector<PathTile*> m_OpenList;
	std::vector<PathTile*> m_ClosedList;
public:

	AStarPathfinding(Map* map)
	{
		SetMap(map);
	}

	void SetMap(Map* map)
	{
		m_map = map;

		mapHeight = m_map->getHeight();
		mapWidth = m_map->getWidth();

		for (unsigned int y = 0; y < mapHeight; y++)
		{
			for (unsigned int x = 0; x < mapWidth; x++)
			{
				PathTile tile{ m_map->Get(Point2D<unsigned int>(x,y)).get() };
				m_ArrayMap.push_back(tile);
			}
		}
	}

	std::vector<MapTile*> FindPath(MapTile* begin, MapTile* end)
	{
		bool pathFound = false;

		Point2D<int> beginPos = begin->GetGridPosition();
		Point2D<int> endPos = end->GetGridPosition();

		PathTile* beginning = getTile(beginPos);
		beginning->g = 0;
		beginning->ComputeH(endPos);
		m_OpenList.push_back(beginning);

		std::vector<PathTile*> adjacent;
		adjacent.reserve(8);

		std::vector<PathTile*>::iterator cur_it;
		PathTile* cur_tile;
		do
		{
			cur_it = std::min_element(m_OpenList.begin(), m_OpenList.end(), [](PathTile* p1, PathTile* p2)
			{
				return p1->f() < p2->f();
			});

			cur_tile = *cur_it;

			if (*cur_tile == endPos)
			{
				// FOUND A PATH
				pathFound = true;
				break;
			}

			m_ClosedList.push_back(cur_tile);
			cur_tile = (*(m_ClosedList.end() - 1));
			m_OpenList.erase(cur_it);


			adjacent.clear();

			auto lambda = [&](int x, int y)
			{
				Point2D<int> pos = (Point2D<int>)*cur_tile + Point2D<int>{x, y};

				if(isValidPos(pos))
				{
					PathTile* val = getTile(pos);

					// If is in closedlist, iterate over it.
					auto it_closed = std::find(m_ClosedList.begin(), m_ClosedList.end(), val);
					if (it_closed != m_ClosedList.end())
					{
						return;
					}

					// If isnt in openlist, add it to the list.
					auto it_open = std::find(m_OpenList.begin(), m_OpenList.end(), val);
					if (it_open == m_OpenList.end())
					{
						val->g = cur_tile->g + ComputeMoveCost(*cur_tile, *val);
						val->ComputeH(endPos);
						val->SetParent(*cur_tile);

						m_OpenList.push_back(val);
					}
					else
					{ // if its already in the open list

						auto new_G = cur_tile->g + ComputeMoveCost(*cur_tile, *val);   // test if using the current G score make the aSquare F score lower, if yes update the parent because it means its a better path
						if (new_G < val->g)
						{
							val->g = new_G;
							val->SetParent(*cur_tile);
						}
					}
				}
			};

			lambda(-1, 1);
			lambda(0, 1);
			lambda(1, 1);
			lambda(-1, 0);
			lambda(1, 0);
			lambda(-1, -1);
			lambda(0, -1);
			lambda(1, -1);

		} while (!m_OpenList.empty());

		// Retrace the pointers from the end to the beginning to create a path.
		if (pathFound)
		{
			std::vector<MapTile*> path;
			MapTile* pathTile;

			path.push_back(end);

			while (!(*cur_tile == (Point2D<unsigned int>)begin->GetGridPosition()))
			{
				pathTile = (m_map->Get((Point2D<unsigned int>)(*cur_tile) + cur_tile->parentDirection)).get();

				path.push_back(pathTile);

				auto it = std::find_if(m_ClosedList.begin(), m_ClosedList.end(), [&](PathTile* p1)
				{
					return *p1 == pathTile->GetGridPosition();
				});

				cur_tile = *it;
			}

			return path;
		}
		else
		{
			return std::vector<MapTile*>{};
		}
	}

	double ComputeMoveCost(const Point2D<int> from, const Point2D<int> to)
	{
		Direction d{ from, to };

		if (d.isDiagonal())
		{
			return m_map->Get(to)->GetDiagCost();
		}
		else
		{
			return m_map->Get(to)->GetCost();
		}
	}

	static constexpr double GetCost()
	{
		return 1.0;
	}

	static constexpr double GetDiagCost()
	{
		return  1.0 *_sqrt<double>(2.0);
	}

	PathTile* getTile(Point2D<int> point)
	{
		return &m_ArrayMap[(mapHeight * point.y) + point.x];
	}

	bool isValidPos(Point2D<int> point)
	{
		return point.x >= 0
			&& point.y >= 0
			&& point.x < mapWidth
			&& point.y < mapHeight;
	}
};