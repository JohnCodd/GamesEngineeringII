#pragma once
#include "Entity.h"

class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() {
		std::cout << "HealthSystem Update" << std::endl;
		for (auto e : entities)
		{
			auto component = dynamic_cast<HealthComponent*>(e.getComponents("HealthComponent"));
			std::cout << "Health: " << component->getHealth() << std::endl;
			component->setHealth(component->getHealth() - 1);
		}
	}
};