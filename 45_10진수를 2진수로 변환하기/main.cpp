#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'

using namespace std;

string solution(int decimal)
{
	if (decimal == 0) return "0"; // 예외처리

	stack<int> stk;
	while (decimal > 0)
	{
		stk.push(decimal % 2);
		decimal /= 2;
	}

	string ret;
	while (!stk.empty())
	{
		ret += to_string(stk.top());
		stk.pop();
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int input = 10;


	string ret = solution(input);
	cout << ret;
}

