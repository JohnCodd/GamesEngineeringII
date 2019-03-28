#include "Game.h"


Game::Game() : m_map(Vector2f(MAP_SIZE.x, MAP_SIZE.y), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)), m_player(Vector2f(SCREEN_WIDTH / MAP_SIZE.x, SCREEN_HEIGHT / MAP_SIZE.y))
{
	//Create window
	m_window = SDL_CreateWindow("A-Star Ambush", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_Renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	m_player.setTexture("./Resources/image.png", *m_Renderer);
	for (int i = 0; i < 10; i++)
	{
		m_ai.push_back(new AI(Vector2f(i+5, 10), Vector2f(SCREEN_WIDTH / MAP_SIZE.x, SCREEN_HEIGHT / MAP_SIZE.y)));
	}
	std::vector<std::vector<AI*>> splitAI;
	for (int i = 0; i < maxThreads; i++)
	{
		m_threadsReady.push_back(false);
		in.push_back(i);
		auto start = m_ai.begin() + (m_ai.size() / maxThreads) * i;
		std::vector<AI*> temp(start, start + (m_ai.size() / maxThreads));
		splitAI.push_back(temp);
	}
	last = in;

	for (int i = 0; i < maxThreads; i++)
	{
		m_threads.push_back(std::thread(threadRun, splitAI.at(i), i, std::ref(m_map), std::ref(m_player)));
	}
}


Game::~Game()
{
}

void Game::loop()
{
	double dt = 0;
	double frameTime = 0;
	double ms_perframe = (1.0 / 30.0);
	auto now = std::chrono::system_clock::now();
	auto before = now;
	while (m_loop)
	{
		now = std::chrono::system_clock::now();
		dt = std::chrono::duration<double>(now - before).count();
		frameTime += dt;
		update(dt);
		if (frameTime > ms_perframe)
		{
			processEvents();
			render();
			frameTime -= ms_perframe;
		}
		before = now;
	}
}

void Game::update(double dt)
{
	for (auto &a : m_ai)
	{
		a->update(dt);
	}
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
					for (auto b : m_threadsReady)
					{
						b = true;
					}

				/*	for (auto &a : m_ai)
					{
						a.setPath(m_map.astarSearch(m_map.getTile(a.getPosition()), m_map.getTile(m_player.getPosition())));
					}*/
					break;
				}
				case SDLK_ESCAPE:
				{
					m_loop = false;
				}
			}
		}
		if (e.type ==  SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			m_map.leftClick(Vector2f(x, y));
			break;
		}
	}
}

void Game::threadRun(std::vector<AI*> ai, int index, Map& m_map, Player& m_player)
{
	while (true)
	{
		for (int j = 0; j < maxThreads - 1; j++)
		{
			in[index] = j;
			last[j] = index;

			for (int k = 0; k < maxThreads - 1; k++)
			{
				while (last[j] == index && k != index)
				{
					//Waiting to run
				}
			}
		}
		mutex.lock();
		//If i have to run astar, run it on the ai
		if (m_threadsReady.at(index))
		{
			//Run astar on the ai

			for (auto &a : ai)
			{
				a->setCanUpdate(false);
				a->setPath(m_map.astarSearch(m_map.getTile(a->getPosition()), m_map.getTile(m_player.getPosition())));
				a->setCanUpdate(true);
			}

			m_threadsReady.at(index) = false;
		}
		mutex.unlock();
		//std::cout << "Executing thread num: " << index << "\n";

		//Last thing to do before exiting
		in[index] = 0; //Exit
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

	for (auto &a : m_ai)
	{
		a->render(*m_Renderer);
	}


	//Update screen
	SDL_RenderPresent(m_Renderer);
}