#include"Factory.h"
#include"Player.h"
#include"Boss.h"

class CharactorFactory : public Factory
{
public:
	Character * CreatePlayer()
	{
		return new Player;
	}
	Character* CreateOpponents()
	{
		return new Boss;
	}
};