
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> vec = { 1, 2, 3 };
	
	do
	{
		for (int element : vec)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	} while (std::next_permutation(vec.begin(), vec.end()));


}

