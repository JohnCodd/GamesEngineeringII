#include "Character.h"
#include <iostream>
#include <string>
#include <vector>

class Boss : public Character
{
public:
	void draw()
	{
		std::cout << "Draw Boss" << std::endl;
	}
};
