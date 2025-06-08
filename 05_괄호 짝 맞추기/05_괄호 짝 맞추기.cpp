
#include <iostream>
#include <stack>
#include <string>
/* 1. 한 글자씩 stack에 top과 현재 문자를 비교한다.
*  2. 쌍이 맞으면 stack에서 pop한다.
*  3. 최종적으로 stack이 empty면 짝이 맞는 것
*/ 

bool solution(std::string str)
{
	std::stack<char> stack;
	// 홀수는 짝이 맞을 수 없으므로
	if (1 == str.length() % 2)
	{
		return false;
	}

	for (size_t i = 0; i < str.length(); i++)
	{
		if (stack.empty())
		{
			stack.push(str[i]);
			continue;
		}
		
		char ch = str[i];
		char top = stack.top();
		if (top == '(' && ch == ')')
		{
			stack.pop();
		}
		else
		{
			stack.push(ch);
		}
	}

	return stack.empty();
}

int main()
{
	std::string str = "((())()";
	bool result = solution(str);
	int a = 0;
}
