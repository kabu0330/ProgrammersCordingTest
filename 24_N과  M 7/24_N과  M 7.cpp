
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8] = {};
vector<int> vec;
bool is_used[8] = {};

void solve(int idx)
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

	for (int i = 0; i < vec.size(); i++)
	{
		arr[idx] = vec[i];
		solve(idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	vec.resize(n);
	for (int i = 0; i < vec.size(); i++)
	{
		cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	
	solve(0);
}
