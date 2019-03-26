#include "Tile.h"



Tile::Tile(SDL_Point p, int tSize) : m_position(p), m_tileSize(tSize)
{
}


Tile::~Tile()
{
}

void Tile::render(SDL_Renderer &renderer)
{
	m_rect = { m_position.x * m_tileSize, m_position.y * m_tileSize, m_tileSize, m_tileSize };
	SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(&renderer, &m_rect);
}