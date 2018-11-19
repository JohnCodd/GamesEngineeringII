#include <assert.h>
#include <vector>
#include <iostream>
#include "../Project 2/Production.h"


int main()
{
	Production p;

	std::vector<int> values = {};

	//Checks for no repeating numbers
	values = { 1, 2, 3, 4, 5, 6 };
	assert(p.play(values) == true);
	std::cout << "Returns true." << std::endl;
	values = { 11, 25, 7, 23, 35 };
	assert(p.play(values) == false);
	std::cout << "Returns false." << std::endl;
	values = { 5, 7, 13, 13, 13, 22 };
	assert(p.play(values) == false);
	std::cout << "Returns false." << std::endl;

	//Checks if numberse are between 1 and 46
	values = { 1, 22, 32, 11, 16, 46 };
	assert(p.play(values) == true);
	std::cout << "Returns true." << std::endl;
	values = { 0, 9, 12, 42, 13, 21 };
	assert(p.play(values) == false);
	std::cout << "Returns false." << std::endl;
	values = { 5, 12, 11, 28, 26, 47 };
	assert(p.play(values) == false);
	std::cout << "Returns false." << std::endl;

	system("PAUSE");
	return 0;
}
