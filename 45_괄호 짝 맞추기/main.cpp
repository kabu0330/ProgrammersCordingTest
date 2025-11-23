#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'

using namespace std;

bool solution(string s)
{
	stack<char> stk;

	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == '(')
		{
			stk.push(ch);
		}
		else
		{
			if (!stk.empty())
			{
				stk.pop();
			}
			else
			{
				return false;
			}
		}
	}


	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input = "(()))()";


	bool ret = solution(input);
	string str = ret ? "true" : "false";
	cout << str;
}

