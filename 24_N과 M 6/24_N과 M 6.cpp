#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = {};
vector<int> vec;
bool is_used[9] = {};

void solve(int idx, int start)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++)
	{
		if (is_used[i] == false)
		{
			arr[idx] = vec[i];
			is_used[i] = true;
			solve(idx + 1, i + 1);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	solve(0, 0);
}
