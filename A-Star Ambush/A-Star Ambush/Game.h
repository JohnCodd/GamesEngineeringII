#pragma once
#include "Player.h"
#include "AI.h"
#include "Map.h"
#include <chrono>
#include <vector>
#include <thread>
#include <mutex>

const float SCREEN_WIDTH = 1066;
const float SCREEN_HEIGHT = 720;
const Vector2f MAP_SIZE = Vector2f(50, 50);
static int maxThreads = 2;
static std::vector<int> in, last;
static std::vector<bool> m_threadsReady;
static std::mutex mutex;

class Game
{
public:
	Game();
	~Game();
	void loop();
	void update(double dt);
	void render(); 
	void processEvents();
	static void threadRun(std::vector<AI*> ai, int index, Map& m_map, Player& m_player);
	enum KeyPressSurfaces
	{
		KEY_PRESS_SURFACE_DEFAULT,
		KEY_PRESS_SURFACE_UP,
		KEY_PRESS_SURFACE_DOWN,
		KEY_PRESS_SURFACE_LEFT,
		KEY_PRESS_SURFACE_RIGHT,
		KEY_PRESS_SURFACE_TOTAL
	};
private:

	std::vector<std::thread> m_threads;
	bool m_loop = true;
	SDL_Window* m_window = NULL;
	SDL_Surface* m_screenSurface = NULL;
	SDL_Renderer* m_Renderer = NULL;
	Player m_player;
	std::vector<AI*> m_ai;
	Map m_map;
};

