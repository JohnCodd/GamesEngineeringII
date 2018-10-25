#pragma once
#include "Command.h"

class ShieldCommand : public Command
{
public:
	ShieldCommand(Player* player) { m_player = player; };
	virtual void execute() { m_player->shield(); };
	virtual void undo() { m_player->undoshield(); };
private:
	Player* m_player;
};