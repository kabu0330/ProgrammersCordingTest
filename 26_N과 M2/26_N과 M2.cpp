#include <iostream>

using namespace std;

int n, m;
int arr[10] = {};
bool is_used[10] = {};

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

	for (int i = 1; i <= n; i++)
	{
		if (is_used[i] == false)
		{
			is_used[i] = true;
			arr[idx] = i;
			solve(idx + 1);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	solve(0);
}

