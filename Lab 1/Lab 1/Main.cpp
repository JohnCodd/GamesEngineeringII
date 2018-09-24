#include <iostream>
#include <string>
#include <vector>
#include "CharacterFactory.h"

int main()
{
	while (true)
	{
		Factory* factory = new CharactorFactory;
		std::vector <Character*> characters;
		characters.push_back(factory->CreatePlayer());
		characters.push_back(factory->CreateOpponents());
		for (int i = 0; i < characters.size(); i++)
		{
			characters[i]->draw();
		}
	}
}