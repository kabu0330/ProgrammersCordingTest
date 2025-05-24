#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main()
{
	int N = 0, M = 0;
	std::cin >> N >> M;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::string Input;
	std::getline(std::cin, Input);

	std::istringstream LineStream(Input);

	int Number = 0;
	std::vector<int> Cards;
	Cards.reserve(N);

	while (LineStream >> Number)
	{
		Cards.push_back(Number);
	}

	int Best = 0;

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int Sum = Cards[i] + Cards[j] + Cards[k];
				if (Sum <= M && Sum > Best)
				{
					Best = Sum;
				}
				if (Best == M)
				{
					break;
				}
			}
		}
	}
	std::cout << Best;
}
