#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> ret;

	int day;
	int max_day = 0;

	for (int i = 0; i < progresses.size(); i++)
	{
		day = (99 - progresses[i]) / speeds[i] + 1;
		
		if (ret.empty() || max_day < day)
		{
			ret.push_back(1);
		}
		else
		{
			++ret.back();
		}

		if (max_day < day)
		{
			max_day = day;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds = { 1, 1, 1, 1, 1, 1 };


	vector<int> ret = solution(progresses, speeds);
}

