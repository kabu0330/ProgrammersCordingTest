
#include <iostream>
#include <vector>

using namespace std;

int n, m;

int maxValue = -1;
vector<int> vec;
vector<int> used;

void backtracking(int idx, int total)
{
	if (idx == 3)
	{
 		if (total <= m)
		{
			maxValue = ::max(maxValue, total);
		}
		return;
	}

	for (int i = idx; i < vec.size(); i++)
	{
		if (used[i] == false)
		{
			used[i] = true;
			backtracking(idx + 1, total + vec[i]);
			used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	vec.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
 
	backtracking(0, 0);
	cout << maxValue;
}
