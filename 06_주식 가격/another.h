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
		while (!s.empty() && prices[s.top()] > prices[i]) // ������ �񱳿����θ� ����ϰ� �ε����� ���õ� ��� �ð��� �������� ����ߴ�.
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