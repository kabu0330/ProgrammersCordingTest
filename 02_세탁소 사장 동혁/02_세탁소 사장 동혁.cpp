#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int Count = 0;
	std::cin >> Count;

	std::queue<int> Remainders;
	for (int i = 0; i < Count; i++)
	{
		int Value = 0;
		std::cin >> Value;
		Remainders.push(Value);
	}
	
	std::vector<std::vector<int>> Answer(Count, std::vector<int>(4, 0));
	int Index = 0;
	const int Coins[4] = { 25, 10, 5, 1 };

	while (false == Remainders.empty())
	{
		int Remainder = Remainders.front();
		Remainders.pop();
		
		for (int i = 0; i < 4; i++)
		{
			Answer[Index][i] = Remainder / Coins[i];
			Remainder %= Coins[i];
		}

		++Index;
	}
	
	for (size_t y = 0; y < Answer.size(); y++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::cout << Answer[y][x] << " ";
		}
		std::cout << std::endl;
	}
}

