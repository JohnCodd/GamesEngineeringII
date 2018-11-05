#include <assert.h>
#include <vector>


class Game
{
public:
	Game() {};

	bool play(std::vector<int> values)
	{
		if (values.size() != 6)
		{
			return false;
		}
		for (auto a : values)
		{
			if (std::count(values.begin(), values.end(), a) != 1)
			{
				return false;
			}
			if (a < 1 || a > 46)
			{
				return false;
			}
		}
		return true;
	};
};

int main()
{
	Game game;

	std::vector<int> values = {};

	//Checks for no repeating numbers
	values = { 1, 2, 3, 4, 5, 6 };
	assert(game.play(values) == true);
	values = { 11, 25, 7, 23, 35 };
	assert(game.play(values) == false);
	values = { 5, 7, 13, 13, 13, 22 };
	assert(game.play(values) == false);

	//Checks if numberse are between 1 and 46
	values = { 1, 22, 32, 11, 16, 46 };
	assert(game.play(values) == true);
	values = { 0, 9, 12, 42, 13, 21 };
	assert(game.play(values) == false);
	values = { 5, 12, 11, 28, 26, 47 };
	assert(game.play(values) == false);
	return 0;
}
