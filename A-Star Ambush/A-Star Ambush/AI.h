#pragma once
#include "Tile.h"
class AI
{
public:
	AI() {};
	AI(Vector2f p, Vector2f tSize);
	~AI();
	void update(float dt);
	void render(SDL_Renderer &renderer);
	void setPath(std::list<Tile> p) { m_path = p; }
	void setCanUpdate(bool b) { m_canUpdate = b; }
	Vector2f getPosition() { return m_position; }
private:
	bool m_canUpdate;
	Vector2f m_position;
	Vector2f m_tileSize;
	SDL_Rect m_rect;
	std::list<Tile> m_path;
	float speed = 0.05;
	float canMove = speed;
};

