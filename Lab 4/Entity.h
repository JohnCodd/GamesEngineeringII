#pragma once
#include "Component.h"
#include <iostream>
#include <map>
#include <vector>
class Entity
{
	int id;
public:
	Entity() {};
	void addComponent(Component& c, std::string name) { components[name] = &c; }
	void removeComponent(Component c) {}
	Component* getComponents(std::string name) { return components[name]; }
private:
	std::map<std::string, Component*> components;
};