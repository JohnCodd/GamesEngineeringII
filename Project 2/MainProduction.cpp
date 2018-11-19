#include <iostream>
#include <string>
#include <sstream>
#include "Production.h"

int main()
{
	Production game = Production();

	std::vector<int> values;
	std::string line;
	double d;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Enter Number " << (i + 1) << ": ";
		while (std::getline(std::cin, line))
		{
			std::stringstream ss(line);
			if (ss >> d)
			{
				if (ss.eof())
				{   // Success
					values.push_back(d);
					break;
				}
			}
			std::cout << "Not a number!" << std::endl;
			std::cout << "Enter Number " << (i + 1) << ": ";
		}
	}
	if (game.play(values) == true)
	{
		std::cout << "Returns True" << std::endl;
	}
	else
	{
		std::cout << "Returns False" << std::endl;
	}
	system("PAUSE");

	return 0;
}