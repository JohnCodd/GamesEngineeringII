#pragma once
#include "Command.h"

class CrouchCommand : public Command
{
public:
	CrouchCommand(Player* player) { m_player = player; };
	virtual void execute() { m_player->crouch(); };
	virtual void undo() { m_player->undocrouch(); };
private:
	Player* m_player;
};