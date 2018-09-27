#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "FireCommand.h"
#include "JumpCommand.h"
#include "CrouchCommand.h"
#include "ShieldCommand.h"
#include "MeleeCommand.h"
#include "InputHandler.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main()
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		SDL_SetMainReady();
		InputHandler handler;
		Player m_player;
		JumpCommand jump = JumpCommand(&m_player);
		FireCommand shoot = FireCommand(&m_player);
		CrouchCommand crouch = CrouchCommand(&m_player);
		ShieldCommand shield = ShieldCommand(&m_player);
		MeleeCommand melee = MeleeCommand(&m_player);
		handler.setCommand("j", &jump);
		handler.setCommand("f", &shoot);
		handler.setCommand("c", &crouch);
		handler.setCommand("s", &shield);
		handler.setCommand("m", &melee);
		bool quit = false;

		SDL_Event e;

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					handler.handleInput(e);

				}

				//Apply the image
				SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	return 0;
}