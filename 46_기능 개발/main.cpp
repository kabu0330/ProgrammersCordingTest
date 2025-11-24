#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> ret;
	queue<int> q;
	queue<int> q2;

	for (int i = 0; i < progresses.size(); i++)
	{
		q.push(progresses[i]);
		q2.push(speeds[i]);
	}

	int day = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		int speed = q2.front();
		q2.pop();


		while (true)
		{
			if (front + speed * day >= 100)
			{
				break;
			}
			++day;
		}

		int cnt = 1;
		while (true)
		{
			if (q.empty() || q2.empty()) break;
			
			if (q.front() + q2.front() * day >= 100)
			{
				++cnt;
				q.pop();
				q2.pop();
				continue;
			}
			else
			{
				break;
			}
		}

		ret.push_back(cnt);
	}
	

	//for (auto& ele : ret)
	//{
	//	cout << ele << " ";
	//}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds = { 1, 1, 1, 1, 1, 1 };


	vector<int> ret = solution(progresses, speeds);
}

