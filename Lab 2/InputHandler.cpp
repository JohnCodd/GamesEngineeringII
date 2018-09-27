#include "InputHandler.h"

void InputHandler::handleInput(SDL_Event& e)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_j:
		button1_->execute();
		undo_ = button1_;
		break;
	case SDLK_f:
		button2_->execute();
		undo_ = button2_;
		break;
	case SDLK_c:
		button3_->execute();
		undo_ = button3_;
		break;
	case SDLK_s:
		button4_->execute();
		undo_ = button4_;
		break;
	case SDLK_m:
		button5_->execute();
		undo_ = button5_;
		break;
	case SDLK_u:
		if (undo_)
		{
			undo_->undo();
			redo_ = undo_;
			undo_ = nullptr;
		}
		break;
	case SDLK_r:
		if (redo_)
		{
			redo_->execute();
			undo_ = redo_;
			redo_ = nullptr;
		}
		break;
	}
}

void InputHandler::setCommand(std::string key, Command * cmd)
{
	if (key == "j")
	{
		button1_ = cmd;
	}
	if (key == "f")
	{
		button2_ = cmd;
	}
	if (key == "c")
	{
		button3_ = cmd;
	}
	if (key == "s")
	{
		button4_ = cmd;
	}
	if (key == "m")
	{
		button5_ = cmd;
	}
}
