
#include <iostream>

using namespace std;

int n, m;
int arr[9] = {};

void solve(int idx, int start_num)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start_num; i <= n; i++)
	{
		arr[idx] = i;
		solve(idx + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	solve(0, 1);
}
