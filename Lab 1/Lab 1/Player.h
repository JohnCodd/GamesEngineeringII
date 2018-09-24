#include "Character.h"
#include <iostream>
#include <string>
#include <vector>

class Player : public Character
{
public:
	void draw()
	{
		std::cout << "Draw Player" << std::endl;
	}
};