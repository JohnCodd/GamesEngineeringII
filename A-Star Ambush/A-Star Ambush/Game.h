#pragma once
#include "Player.h"
#include "AI.h"
#include "Map.h"

const float SCREEN_WIDTH = 1066;
const float SCREEN_HEIGHT = 720;
const Vector2f MAP_SIZE = Vector2f(50, 50);

class Game
{
public:
	Game();
	~Game();
	void loop();
	void update();
	void render(); 
	void processEvents();
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
	bool m_loop = true;
	SDL_Window* m_window = NULL;
	SDL_Surface* m_screenSurface = NULL;
	SDL_Renderer* m_Renderer = NULL;
	Player m_player;
	AI m_ai;
	Map m_map;
};

