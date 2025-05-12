#include <iostream>
#include <vector>
#include <limits>

int main()
{
    std::vector<std::vector<int>> Matrix(9, std::vector<int>(9, 0));

	int Max = std::numeric_limits<int>::min();

	std::pair<int, int> Index;
	for (size_t y = 0; y < Matrix.size(); y++)
	{
		std::vector<int> Values(Matrix[0].size());
		for (size_t x = 0; x < Matrix[0].size(); x++)
		{
			std::cin >> Values[x];
			if (Values[x] > Max)
			{
				Max = Values[x];
				Index.first = y + 1;
				Index.second = x + 1;
			}
		}
		Matrix[y] = Values;
	}
	std::cout << Max << std::endl;
	std::cout << Index.first << " " << Index.second << std::endl;
}
