#include "Command.h"

class JumpCommand : public Command
{
public:
	JumpCommand(Player* player) { m_player = player; };
	virtual void execute() { m_player->jump(); };
	virtual void undo() { m_player->undojump(); };
private:
	Player* m_player;
};