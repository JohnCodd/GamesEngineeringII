#pragma once
#include "SDL.h"
#include <stdio.h>
#include <list>
#include <iostream>
class Tile
{
public:
	Tile() {};
	Tile(SDL_Point p, int tSize);
	~Tile();
	void render(SDL_Renderer &renderer);
	void setGCost(double g) { m_gCost = g; }
	void setHCost(double h) { m_hCost = h; }
	void setCost(double c) { m_cost = c; }
	void addEdge(Tile& t) { adj.push_back(&t); }
	double getGCost() { return m_gCost; }
	double getHCost() { return m_hCost; }
	double getCost() { return m_cost; }
	std::list<Tile*> getAdj() { return adj; }
	bool operator==(Tile t) { return (m_position.x == t.m_position.x && m_position.y == t.m_position.y); }
private:
	int m_tileSize;
	double m_gCost;
	double m_hCost;
	double m_cost;
	std::list<Tile*> adj;
	SDL_Point m_position;
	SDL_Rect m_rect;
};

