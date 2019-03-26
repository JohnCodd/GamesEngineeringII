#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

class Player
{
public:
	Player();
	~Player();
	void setTexture(std::string path, SDL_Renderer& renderer);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void render(SDL_Renderer& renderer);
private:
	int m_speed = 10;
	SDL_Point m_position;
	SDL_Rect m_rect;
	SDL_Texture* m_texture;
};

