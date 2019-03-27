#include "Game.h"



Game::Game() : m_map(Vector2f(MAP_SIZE.x, MAP_SIZE.y), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)), m_player(Vector2f(SCREEN_WIDTH / MAP_SIZE.x, SCREEN_HEIGHT / MAP_SIZE.y))
{
	//Create window
	m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_Renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	m_player.setTexture("./Resources/image.png", *m_Renderer);
	m_ai = AI(Vector2f(10, 10), Vector2f(SCREEN_WIDTH / MAP_SIZE.x, SCREEN_HEIGHT / MAP_SIZE.y));
}


Game::~Game()
{
}

void Game::loop()
{
	while (m_loop)
	{
		processEvents();
		update();
		render();
	}
}

void Game::update()
{
	m_ai.update();
}

void Game::processEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			m_loop = false;
		}
		//User presses a key
		else if (e.type == SDL_KEYDOWN)
		{
			//Select surfaces based on key press
			switch (e.key.keysym.sym)
			{
				case SDLK_UP:
				{
					m_player.moveUp();
					break;
				}
				case SDLK_DOWN:
				{
					m_player.moveDown();
					break;
				}
				case SDLK_RIGHT:
				{
					m_player.moveRight();
					break;
				}
				case SDLK_LEFT:
				{
					m_player.moveLeft();
					break;
				}
				case SDLK_SPACE:
				{
					m_ai.setPath(m_map.astarSearch(m_map.getTile(Vector2f(0, 0)), m_map.getTile(Vector2f(5, 5))));
					break;
				}
				case SDLK_ESCAPE:
				{
					m_loop = false;
				}
			}
		}
	}
}

void Game::render()
{
	//Clear screen
	SDL_RenderClear(m_Renderer);
	SDL_Rect background = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(m_Renderer, &background);
	m_map.render(*m_Renderer);
	m_player.render(*m_Renderer);
	m_ai.render(*m_Renderer);


	//Update screen
	SDL_RenderPresent(m_Renderer);
}