#pragma once
#include "Player.h"
#include "Map.h"

const int SCREEN_WIDTH = 1066;
const int SCREEN_HEIGHT = 720;

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
	Map m_map;
};

