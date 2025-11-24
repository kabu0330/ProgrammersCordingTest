#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>


#define endl '\n'

using namespace std;

vector<int> solution(vector<int> vec)
{
	// 가격을 저장
	vector<int> ret(vec.size());

	// 인덱스를 저장
	stack<int> stk;

	for (int i = 0; i < vec.size(); i++)
	{
		while (!stk.empty() && vec[stk.top()] > vec[i])
		{
			vec[stk.top()] = i - stk.top();
			stk.pop();
		}

		stk.push(i);
	}

	while (!stk.empty())
	{
		vec[stk.top()] = vec.size() - stk.top() - 1;
		stk.pop();
	}

	for (auto& ele : ret)
	{
		cout << ele << " ";
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> input = { 1, 2, 3, 2, 3 };


	vector<int> ret = solution(input);
}

