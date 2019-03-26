#pragma once
#include "Tile.h"
#include <map>
#include <list>
#include <iostream>
class Map
{
public:
	Map();
	~Map();
	void render(SDL_Renderer &renderer);
	Tile& getTile(std::pair<int, int> pos) { return m_tiles[pos]; }
	std::list<Tile&> astarSearch(Tile& start, Tile& goal);
private:
	std::map<std::pair<int,int>, Tile> m_tiles;
};

