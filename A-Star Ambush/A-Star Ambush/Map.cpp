#include "Map.h"



Map::Map()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			SDL_Point p = { j, i };
			std::pair<int, int> pairPos;
			pairPos.first = p.x;
			pairPos.second = p.y;
			m_tiles[pairPos] = Tile(p, 50);
			std::pair<int, int> adj;
			if (i > 0)
			{
				adj = std::make_pair(j, i - 1);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
			if (j + 1 < 50)
			{
				adj = std::make_pair(j + 1, i);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
			if (i + 1 < 50)
			{
				adj = std::make_pair(j, i + 1);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
			if (j > 0)
			{
				adj = std::make_pair(j - 1, i);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
		}
	}
}


Map::~Map()
{
}

void Map::render(SDL_Renderer & renderer)
{
	for (auto &t : m_tiles)
	{
		t.second.render(renderer);
	}
}

std::list<Tile&> Map::astarSearch(Tile & start, Tile & goal)
{
	std::list<Tile> openList;
	std::list<Tile> closedList;

	openList.push_back(start);

	while (openList.size() > 0)
	{
		Tile current = openList.front();
		openList.pop_front();
		closedList.push_back(current);
		if (current == goal)
		{

		}
	}

	return std::list<Tile&>();
}
