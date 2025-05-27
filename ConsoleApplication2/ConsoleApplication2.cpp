#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string str = "APPLE";
	str += ", World!";

	str.replace(7, 4, "Col");
	std::cout << str << std::endl;

	std::vector<int> vec = { 1, 4, 3, 4, 5, 4, 5 };
	int result = std::count(vec.begin(), vec.end(), 5);

	std::cout << result << std::endl;
}
