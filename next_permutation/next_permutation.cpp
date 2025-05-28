
#include <iostream>
#include <algorithm>
#include <vector>

void PrintPermutation(const std::vector<int>& _vec)
{
	for (const int& element : _vec) {
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

int main()
{
	std::vector<int> vec = { 1, 2, 3 };
	
	do {
		PrintPermutation(vec);
	} 
	while (std::next_permutation(vec.begin(), vec.end()));
	
}
