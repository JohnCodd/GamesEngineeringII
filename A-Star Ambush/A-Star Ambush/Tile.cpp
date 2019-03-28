#include "Tile.h"



Tile::Tile(Vector2f p, Vector2f tSize) : m_position(p), m_tileSize(tSize)
{
}


Tile::~Tile()
{
}

void Tile::render(SDL_Renderer &renderer)
{
	m_rect = { static_cast<int>(m_position.x * m_tileSize.x), static_cast<int>(m_position.y * m_tileSize.y), static_cast<int>(m_tileSize.x), static_cast<int>(m_tileSize.y) };
	switch (m_type)
	{
	case Wall:
		SDL_SetRenderDrawColor(&renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(&renderer, &m_rect);
		break;

	default:
		SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderDrawRect(&renderer, &m_rect);
		break;
	}
	
}