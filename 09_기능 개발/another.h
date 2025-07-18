#pragma once

#include <queue>
#include <vector>

using namespace std;

vector<int> solution2(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	
	int n = progresses.size();
	vector<int> days_left(n);
	for (int i = 0; i < n; i++)
	{
		days_left[i] = ceil((100 - progresses[i]) / speeds[i]);
	}

	int count = 0;
	int max_day = days_left[0];

	for (int i = 0; i < n; i++)
	{
		if (days_left[i] <= max_day)
		{
			count++;
		}
		else
		{
			answer.push_back(count);
			count = 1;
			max_day = days_left[i];
		}
	}
	
	answer.push_back(count);

	return answer;
}