#pragma once
#include "SDL.h"
#include "Vector2f.h"
#include <stdio.h>
#include <list>
#include <iostream>
class Tile
{
public:
	Tile() {};
	Tile(Vector2f p, Vector2f tSize);
	~Tile();
	void render(SDL_Renderer &renderer);
	void setGCost(double g) { m_gCost = g; }
	void setHCost(double h) { m_hCost = h; }
	void setCost(double c) { m_cost = c; }
	void setPrevious(Tile &t) { m_previous = &t; }
	void addEdge(Tile& t) { adj.push_back(&t); }
	float getGCost() { return m_gCost; }
	float getHCost() { return m_hCost; }
	float getCost() { return m_cost; }
	Tile* getPrevious() { return m_previous; }
	Vector2f getPosition() { return m_position; }
	std::list<Tile*> getAdj() { return adj; }
	bool operator==(Tile t) { return (m_position.x == t.m_position.x && m_position.y == t.m_position.y); }
private:
	Vector2f m_position;
	Vector2f m_tileSize;
	float m_gCost = 0;
	float m_hCost = 0;
	float m_cost = 0;
	std::list<Tile*> adj;
	Tile* m_previous = nullptr;
	SDL_Rect m_rect;
};

