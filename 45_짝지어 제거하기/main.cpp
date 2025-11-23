#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'

using namespace std;

int solution(string vec)
{
	stack<char> stk;

	for (int i = 0; i < vec.size(); i++)
	{
		if (stk.empty())
		{
			stk.push(vec[i]);
		}
		else
		{
			if (stk.top() == vec[i])
			{
				stk.pop();
			}
			else
			{
				stk.push(vec[i]);
			}
		}
	}
	return stk.empty() ? 1 : 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input = "baabaa";


	int ret = solution(input);
	cout << ret;
}

