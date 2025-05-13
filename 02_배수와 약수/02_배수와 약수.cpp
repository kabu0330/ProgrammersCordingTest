
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> Inputs;
	int Value = 0;
	while (std::cin >> Value)
	{
		if (0 == Value)
		{
			break;
		}
		Inputs.push_back(Value);
	}

	int First = 0;
	int Second = 0;
	std::vector<std::string> Answer((Inputs.size() / 2) - 1, "");
	int Index = 0;
	for (size_t i = 0; i < Inputs.size(); i++)
	{
		if (1 == i % 2)
		{
			First = Inputs[i];
			continue;
		}
		else
		{
			if (0 == First && 0 == Inputs[i])
			{
				break;
			}

			Second = Inputs[i];
		}
		
		if (0 == Second % First)
		{
			Answer[Index] = "factor";
		}
		else if (0 == First % Second)
		{
			Answer[Index] = "multiple";
		}
		else
		{
			Answer[Index] = "neither";
		}
		
		++Index;
	}

	for (size_t i = 0; i < Answer.size(); i++)
	{
		std::cout << Answer[i] << std::endl;
	}
}

