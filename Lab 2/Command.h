#pragma once
#include "Player.h"
#include "SDL.h"
#include <iostream>

class Command
{
public:
	Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
};