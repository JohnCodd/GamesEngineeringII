#pragma once
#include "Tile.h"
#include <map>
#include <list>
#include <iostream>
struct VectorComparator
{
	bool operator() (Vector2f lhs, Vector2f rhs) const
	{
		return std::tie(lhs.x, rhs.y) < std::tie(rhs.x, lhs.y);
	}
};
class Map
{
public:
	Map(Vector2f mapSize, Vector2f windowSize);
	~Map();
	void render(SDL_Renderer &renderer);
	Tile& getTile(Vector2f pos) { return m_tiles[pos]; }
	std::list<Tile> astarSearch(Tile& start, Tile& goal);
private:
	std::map<Vector2f, Tile, VectorComparator> m_tiles;
};

