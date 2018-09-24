#include "Character.h"

class Player
{
public:
	Player() : character(new Character()) {}
	Character* operator->() { return character; }
private:
	Character * character;
};