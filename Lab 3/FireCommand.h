#include "Command.h"

class FireCommand : public Command
{
public:
	FireCommand(Player* player) { m_player = player; };
	virtual void execute() { m_player->shoot(); };
	virtual void undo() { m_player->undoshoot(); };
private:
	Player * m_player;
};