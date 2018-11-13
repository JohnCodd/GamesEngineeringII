#include<vector>
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