
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	bool Result1 = std::binary_search(vec.begin(), vec.end(), 3);



	bool Result2 = std::binary_search(vec.begin(), vec.end(), 7);

}

