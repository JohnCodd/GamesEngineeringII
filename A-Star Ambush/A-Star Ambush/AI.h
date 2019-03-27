#pragma once
#include "Tile.h"
class AI
{
public:
	AI() {};
	AI(Vector2f p, Vector2f tSize);
	~AI();
	void update();
	void render(SDL_Renderer &renderer);
	void setPath(std::list<Tile> p) { m_path = p; }
private:
	Vector2f m_position;
	Vector2f m_tileSize;
	SDL_Rect m_rect;
	std::list<Tile> m_path;
};

