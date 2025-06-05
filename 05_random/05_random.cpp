#include <iostream>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);
	int answer0 = -1;
	int answer1 = -1;

	for (int i = 0; i < 10; i++)
	{
		answer0 = dist(gen);
		answer1 = dist(gen);
		std::cout << answer0 << ", " << answer1 << std::endl;
		std::cout << "\n";
	}
}
