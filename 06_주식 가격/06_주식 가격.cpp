
#include <iostream>
#include <stack>
#include <vector>
#include "another.h"

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> time(prices.size(), 0);
	stack<int> max_price;

	for (size_t i = 0; i < prices.size(); i++)
	{
		if (true == max_price.empty())
		{
			max_price.push(prices[i]);
			continue;
		}

		if (max_price.top() < prices[i])
		{
			max_price.push(prices[i]);
		}
		else
		{
			int total_time = 1;
			int index = -1;
			while (false == max_price.empty() && max_price.top() > prices[i])
			{
				max_price.pop();
				time[i + index] = total_time;
				++total_time;
				--index;
			}

			max_price.push(prices[i]);
		}
		
	}

	int index = prices.size() - 1;
	int total_time = 0;
	while (false == max_price.empty())
	{
		if (0 == time[index])
		{
			time[index] = total_time;
			max_price.pop();
		}

		--index;
		++total_time;
	}
	
	return time;
}

int main()
{
	vector<int> prices = { 1, 2, 3, 2, 3 };
	vector<int> result = solution(prices);
	vector<int> result2 = solution2(prices);

	int a = 0;
}
