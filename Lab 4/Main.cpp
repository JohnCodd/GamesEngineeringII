#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <stdio.h>
#include "Entity.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "ControlComponent.h"
#include "ControlSystem.h"

int main(void*)
{
	Entity player;
	HealthComponent hc;
	ControlComponent cc;
	player.addComponent(hc, "HealthComponent");
	player.addComponent(cc, "ControlComponent");
	HealthSystem hs;
	ControlSystem cs;
	hs.addEntity(player);
	cs.addEntity(player);
	while (true)
	{
		hs.update();
		cs.update();

	}
	return 0;
}