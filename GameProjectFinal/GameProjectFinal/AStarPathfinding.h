#pragma once

#include <vector>
#include <algorithm>
#include <math.h>

#include "Map.h"
#include "Direction.h"

class AStarPathfinding
{
	struct PathTile
	{
		using value_type = double;

		value_type g;
		value_type h;
		value_type f() { return g + h; }

		MapTile* tile;
		Direction parentDirection;

		PathTile(MapTile* tile) :
			tile{ tile },
			g{ std::numeric_limits<double>::infinity() },
			h{ 0.0 },
			parentDirection{}
		{
		}

		void ComputeH(const PathTile& end)
		{
			const auto deltaX = std::abs(tile->GetPosition().x - end.tile->GetPosition().x);
			const auto deltaY = std::abs(tile->GetPosition().y - end.tile->GetPosition().y);

			const auto min = min(deltaX, deltaY);
			const auto max = max(deltaX, deltaY);

			const auto diff = max - min;

			//			   Diagonnal cost.					Axis cost.
			const auto H = (min * end.tile->GetDiagCost()) + (diff * end.tile->GetCost());

			h = H;
		}

		void SetParent(PathTile& parentTile)
		{
			parentDirection = Direction{ *tile, *parentTile.tile };
		}

		inline bool operator==(const PathTile& rhs) { return *tile == *rhs.tile; };
	};

	Map* m_map;
	std::vector<PathTile> m_OpenList;
	std::vector<PathTile> m_ClosedList;

public:

	AStarPathfinding(Map* map) :
		m_map{ map }
	{
	}

	std::vector<MapTile*> FindPath(MapTile* begin, MapTile* end)
	{
		bool pathFound = false;

		PathTile beginning{ begin };
		beginning.g = 0;
		beginning.ComputeH(end);
		m_OpenList.push_back(beginning);

		PathTile ending{ end };

		std::vector<PathTile> adjacent;
		adjacent.reserve(8);

		std::vector<PathTile>::iterator cur_it;
		PathTile* cur_tile;
		do
		{
			cur_it = std::min_element(m_OpenList.begin(), m_OpenList.end(), [](PathTile& p1, PathTile& p2)
			{
				return p1.f() < p2.f();
			});

			cur_tile = &(*cur_it);

			if (*cur_tile->tile == *end)
			{
				// FOUND A PATH
				pathFound = true;
				break;
			}

			Point3D<int> pos = cur_tile->tile->GetGridPosition();
			m_ClosedList.push_back(*cur_tile);
			cur_tile = &(*(m_ClosedList.end() - 1));
			m_OpenList.erase(cur_it);


			adjacent.clear();

			auto lambda = [&](int x, int y)
			{
				try
				{
					adjacent.push_back(PathTile{ m_map->Get(pos + Point2D<int>{x, y}).get() });
				}
				catch (OutOfBoundsException)
				{
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

			for (auto& val : adjacent)
			{
				// If is in closedlist, iterate over it.
				auto it_closed = std::find(m_ClosedList.begin(), m_ClosedList.end(), val);
				if (it_closed != m_ClosedList.end())
				{
					continue;
				}

				// If isnt in openlist, add it to the list.
				auto it_open = std::find(m_OpenList.begin(), m_OpenList.end(), val);
				if (it_open == m_OpenList.end())
				{
					val.g = cur_tile->g + ComputeMoveCost(*cur_tile, val);
					val.ComputeH(ending);
					val.SetParent(*cur_tile);
					
					m_OpenList.push_back(val);
				}
				else 
				{ // if its already in the open list

					auto new_G = cur_tile->g + ComputeMoveCost(*cur_tile, val);   // test if using the current G score make the aSquare F score lower, if yes update the parent because it means its a better path
					if (new_G < val.g)
					{
						val.g = new_G;
						val.SetParent(*cur_tile);
					}
				}
			}

			for (auto& val : adjacent)
			{
				// If is in closedlist, iterate over it.
				auto it_closed = std::find(m_ClosedList.begin(), m_ClosedList.end(), val);
				if (it_closed != m_ClosedList.end())
				{
					continue;
				}

				// If isnt in openlist, add it to the list.
				auto it_open = std::find(m_OpenList.begin(), m_OpenList.end(), val);
				if (it_open == m_OpenList.end())
				{
					val.g = cur_tile->g + ComputeMoveCost(*cur_tile, val);
					val.ComputeH(ending);
					val.SetParent(*cur_tile);

					m_OpenList.push_back(val);
				}
				else
				{ // if its already in the open list

					auto new_G = cur_tile->g + ComputeMoveCost(*cur_tile, val);   // test if using the current G score make the aSquare F score lower, if yes update the parent because it means its a better path
					if (new_G < val.g)
					{
						val.g = new_G;
						val.SetParent(*cur_tile);
					}
				}
			}
		} while (!m_OpenList.empty());

		// Retrace the pointers from the end to the beginning to create a path.
		if (pathFound)
		{
			std::vector<MapTile*> path;
			MapTile* pathTile;

			path.push_back(end);

			while (!(*cur_tile->tile == *begin))
			{
				try
				{
					pathTile = m_map->Get((Point2D<size_t>)(cur_tile->tile->GetGridPosition() + (Point3D<int>)cur_tile->parentDirection)).get();
				}
				catch (OutOfBoundsException)
				{
				}


				path.push_back(pathTile);

				auto it = std::find_if(m_ClosedList.begin(), m_ClosedList.end(), [&](PathTile& p1)
				{
					return p1.tile->GetPosition() == pathTile->GetPosition();
				});

				cur_tile = &(*it);
			}

			return path;
		}
		else
		{

		}
	}

	double ComputeMoveCost(PathTile& from, PathTile& to)
	{
		Direction d{ *(from.tile), *(to.tile) };

		if (d.isDiagonal())
		{
			return to.tile->GetDiagCost();
		}
		else
		{
			return to.tile->GetCost();
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

};