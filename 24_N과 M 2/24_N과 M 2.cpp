
#include <iostream>

using namespace std;

int n, m;
int arr[10] = {};
bool is_used[10] = { false };

void solve(int idx, int start_num)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = start_num; i <= n; i++)
	{
		if (false == is_used[i])
		{
			arr[idx] = i;
			is_used[i] = true;
			solve(idx + 1, i + 1);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	solve(0, 1);
}
