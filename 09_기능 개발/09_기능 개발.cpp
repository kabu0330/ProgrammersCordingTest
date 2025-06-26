

#include <iostream>
#include <queue>
#include <vector>
#include "another.h"

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;

	queue<int> queue;
	for (size_t i = 0; i < progresses.size(); i++)
	{
		queue.push(progresses[i]);
	}
	
	int duration = 0;
	int index = 0;
	while (false == queue.empty())
	{
		int count = 0;
		int front = queue.front();
		front += duration * speeds[index];

		while (100 > front)
		{
			++duration;
			front += speeds[index];
		}

		bool bisfinish = true;
		while (bisfinish)
		{
			++count;
			++index;
			queue.pop();

			if (queue.empty())
			{
				answer.push_back(count);
				break;
			}

			int next = queue.front();
			next += duration * speeds[index];
			if (100 <= next)
			{
				continue;
			}
			else
			{
				answer.push_back(count);
				bisfinish = false;
				continue;
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };
	vector<int> result = solution(progresses, speeds);
	vector<int> result2 = solution2(progresses, speeds);
}
