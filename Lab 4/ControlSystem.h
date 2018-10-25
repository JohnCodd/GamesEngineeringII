#pragma once
#include "Entity.h"

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update()
	{
		std::cout << "ControlSystem Update" << std::endl;

	}
};