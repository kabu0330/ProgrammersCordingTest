#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string Number = "";
	int NumberSystem = 0;
	std::cin >> Number >> NumberSystem;
	int Num = std::atoi(Number.data());

	std::stack<int> Remainders;
	while (0 != Num)
	{
		int Quotient = Num / NumberSystem;
		int Remainder = Num % NumberSystem;
		Num = Quotient;
		Remainders.push(Remainder);	
	}
	
	std::string Result = "";

	while (false == Remainders.empty())
	{
		int Value = Remainders.top();
		Remainders.pop();

		char Char = 0;
		if (9 < Value)
		{
			// 65(A) = 10 + 55
			// 90(Z) = 35 + 55 
			Char = Value + 55;
		}
		else
		{
			Char = Value + '0';
		}

		Result += Char;
	}

	for (size_t i = 0; i < Result.length(); i++)
	{
		std::cout << Result[i];
	}
}

