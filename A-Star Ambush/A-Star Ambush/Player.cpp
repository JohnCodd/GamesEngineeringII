#include "Player.h"



Player::Player(Vector2f tSize)
{
	m_position = { 0,0 };
	m_tileSize = tSize;
}


Player::~Player()
{
}

void Player::moveUp()
{
	m_position.y -= 1;
}

void Player::moveRight()
{
	m_position.x += 1;
}

void Player::moveDown()
{
	m_position.y += 1;
}

void Player::moveLeft()
{
	m_position.x -= 1;
}

void Player::render(SDL_Renderer& renderer)
{
	m_rect = { static_cast<int>(m_position.x * m_tileSize.x), static_cast<int>(m_position.y * m_tileSize.y), static_cast<int>(m_tileSize.x), static_cast<int>(m_tileSize.y) };
	SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(&renderer, &m_rect);
}

void Player::setTexture(std::string path, SDL_Renderer& renderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(&renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	m_texture = newTexture;
}