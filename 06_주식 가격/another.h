#pragma once
#include <vector>
#include <stack>

using namespace std;

vector<int>solution2(vector<int> prices)
{
	vector<int> answer(prices.size());
	stack<int> s;

	int priceNum = prices.size();
	for (int i = 0; i < priceNum; i++)
	{		
		while (!s.empty() && prices[s.top()] > prices[i]) // 가격은 비교용으로만 사용하고 인덱스도 스택도 모두 시간을 기준으로 사용했다.
		{
			int sTop = s.top();
			answer[s.top()] = i - s.top();
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		answer[s.top()] = priceNum - s.top() - 1;
		s.pop();
	}

	return answer;
}