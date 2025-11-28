#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define endl '\n'

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
	queue<string> q;

	for (const string& str : goal)
	{
		q.push(str);
	}
	
	int cards1Idx = 0;
	int cards2Idx = 0;
	while (!q.empty())
	{
		string str = q.front();
		q.pop();

		if (cards1.size() > cards1Idx && str == cards1[cards1Idx])
		{
			cards1Idx++;
			continue;
		}

		if (cards2.size() > cards2Idx && str == cards2[cards2Idx])
		{
			cards2Idx++;
			continue;
		}

		return "No";
	}

	return "Yes";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<string> cards1 = { "i", "water", "drink" };
	vector<string> cards2 = { "want", "to" };
	vector<string> goal = { "i", "want", "to", "drink", "water" };

	string ret = solution(cards1, cards2, goal);

	cout << ret << " ";
}

