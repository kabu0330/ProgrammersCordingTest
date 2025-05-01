#include <iostream>
#include "solution.h"

int main()
{
	std::cout << solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} }) << std::endl;
	std::cout << solution(3, { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} }) << std::endl;
}
