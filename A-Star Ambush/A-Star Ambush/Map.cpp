#include "Map.h"
#include <math.h>


Map::Map(Vector2f mapSize, Vector2f windowSize)
{
	for (int i = 0; i < mapSize.y; i++)
	{
		for (int j = 0; j < mapSize.x; j++)
		{
			Vector2f p = Vector2f(j, i);
			Vector2f pairPos;
			pairPos = p;
			m_tSize = Vector2f(windowSize.x / mapSize.x, windowSize.y / mapSize.y);
			m_tiles[pairPos] = Tile(p, m_tSize);
			Vector2f adj;
			if (i > 0)
			{
				adj = Vector2f(j, i - 1);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
			if (j + 1 < mapSize.x)
			{
				adj = Vector2f(j + 1, i);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
			if (i + 1 < mapSize.y)
			{
				adj = Vector2f(j, i + 1);
				m_tiles[pairPos].addEdge(m_tiles[adj]);
			}
			if (j > 0)
			{
				adj = Vector2f(j - 1, i);
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

void Map::leftClick(Vector2f pos)
{
	Vector2f mousePosition = Vector2f(floor(pos.x / m_tSize.x), floor(pos.y / m_tSize.y));
	m_tiles[mousePosition].setType(Tile::TileType::Wall);
}

std::list<Tile> Map::astarSearch(Tile & start, Tile & goal)
{
	std::list<Tile*> openList;
	std::list<Tile*> closedList;
	
	start.setPrevious(nullptr);
	for (auto&t : m_tiles)
	{
		t.second.setPrevious(nullptr);
		t.second.setCost(9999);
		t.second.setGCost(9999);
		t.second.setHCost(9999);
	}
	openList.push_back(&start);

	while (openList.size() > 0)
	{
		Tile* current = openList.front();
		for (auto &opent : openList)
		{
			if (opent->getCost() < current->getCost())
			{
				current = opent;
			}
		}
		openList.remove(*std::find(openList.begin(),openList.end(), current));
		closedList.push_back(current);
		if (*current == goal)
		{
			std::list<Tile> output;
			Tile* previous = current;
			while (previous != nullptr)
			{
				output.push_front(*previous);
				previous = previous->getPrevious();
			}
			return output;
		}
		else
		{
			for (auto &t : current->getAdj())
			{
				bool isClosed = false;
				for (auto &closedt : closedList)
				{
					if (t == closedt)
					{
						isClosed = true;
					}
				}
				if (!isClosed && t->getType() != Tile::TileType::Wall)
				{

					bool alreadyInOpen = false;
					for (auto &opent : openList)
					{
						if (t == opent && t->getGCost() > opent->getGCost())
						{
							alreadyInOpen = true;
							break;
						}

					}
					if (alreadyInOpen == false)
					{
						t->setGCost(current->getGCost() + 1.0f);
						Vector2f goalPos = goal.getPosition();
						float distance = t->getPosition().distance(goalPos);
						t->setHCost(distance);
						t->setCost(t->getGCost() + t->getHCost());
						t->setPrevious(current);
						openList.push_back(t);
					}
				}
			}
		}
	}

	return std::list<Tile>();
}
