#include <iostream>
#include <string>

int main()
{
	std::string str = "APPLE";
	str += ", World!";

	str.replace(7, 4, "Col");
	std::cout << str << std::endl;
}
