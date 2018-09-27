#pragma once
#include "Command.h"

class MeleeCommand : public Command
{
public:
	MeleeCommand(Player* player) { m_player = player; };
	virtual void execute() { m_player->melee(); };
	virtual void undo() { m_player->undomelee(); };
private:
	Player* m_player;
};