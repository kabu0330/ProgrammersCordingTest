#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

vector<int> vec;
vector<int> result;
int target = 6;

void solve(int start, int depth)
{
	if (depth == target)
	{
		for (int ele : result)
		{
			cout << ele << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < vec.size(); i++)
	{
		result.push_back(vec[i]);
		solve(i + 1, depth + 1);
		result.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		vec.clear();
		vec.resize(k);
		for (int i = 0; i < k; i++)
		{
			cin >> vec[i];
		}

		solve(0, 0);
		cout << '\n';
	}
}

