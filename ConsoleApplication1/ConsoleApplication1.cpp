#include <iostream>
#include <string>
#include <vector>

int main()
{
	int Size = 0;
	std::cin >> Size;

	std::string Str;
	std::cin >> Str;

	int Result = 0;
	for (size_t i = 0; i < Str.length(); i++)
	{
		char Text = Str[i];
		Result += static_cast<int>(Text - '0');
	}

	std::cout << Result;

}