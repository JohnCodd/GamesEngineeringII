#include "AI.h"



AI::AI(Vector2f p, Vector2f tSize) : m_position(p), m_tileSize(tSize),
	m_canUpdate(true)
{
}


AI::~AI()
{
}

void AI::update(float dt)
{
	if (m_canUpdate)
	{
		if (m_path.size() > 0)
		{
			canMove -= dt;
			if (canMove <= 0)
			{
				m_position = m_path.front().getPosition();
				m_path.pop_front();
				canMove = speed;
			}
		}
	}
}

void AI::render(SDL_Renderer &renderer)
{
	m_rect = { static_cast<int>(m_position.x * m_tileSize.x), static_cast<int>(m_position.y * m_tileSize.y), static_cast<int>(m_tileSize.x), static_cast<int>(m_tileSize.y) };
	SDL_SetRenderDrawColor(&renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(&renderer, &m_rect);
}