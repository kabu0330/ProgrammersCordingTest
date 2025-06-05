#include <iostream>

int main()
{
	try
	{
		std::cout << "try-catch-throw 예외 던지기" << std::endl;
		throw 1;
   }
	catch (int a)
	{
		std::cout << "1 예외 캐치" << std::endl;
	}
}
