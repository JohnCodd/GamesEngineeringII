#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2f.h"
#include <stdio.h>
#include <iostream>

class Player
{
public:
	Player(Vector2f tSize);
	~Player();
	void setTexture(std::string path, SDL_Renderer& renderer);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void render(SDL_Renderer& renderer);
	Vector2f getPosition() { return m_position; }
private:
	Vector2f m_tileSize;
	Vector2f m_position;
	SDL_Rect m_rect;
	SDL_Texture* m_texture;
};

