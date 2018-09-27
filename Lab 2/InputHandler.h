#pragma once
#include "Command.h"
#include <string>

class InputHandler
{
public:
	void handleInput(SDL_Event& e);
	void setCommand(std::string key, Command* cmd);
private:
	Command* button1_;
	Command* button2_;
	Command* button3_;
	Command* button4_;
	Command* button5_;
	Command* undo_ = nullptr;
	Command* redo_ = nullptr;
};