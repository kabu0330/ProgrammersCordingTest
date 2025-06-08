
#include <iostream>
#include <stack>
#include <string>

std::string solution(int value)
{
	if (0 == value)
	{
		return "0";
	}
	std::stack<int> stack;
	while (0 != value)
	{
		if (0 == (value % 2))
		{
			stack.push(0);
		}
		else
		{
			stack.push(1);
		}
		value /= 2;
	}
	std::string result;
	while (false == stack.empty())
	{
		result += (char)(stack.top() + '0');
		stack.pop();
	}
	return result;
}

int main()
{
	int decimal = 27;
	std::string result = solution(decimal);
}
