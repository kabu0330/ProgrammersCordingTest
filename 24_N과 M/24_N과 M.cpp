
#include <iostream>

using namespace std;

int n, m;
int arr[10] = {};
bool is_used[10] = { false };

void solve(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (false == is_used[i])
		{
			arr[k] = i;
			is_used[i] = true;
			solve(k + 1);
			is_used[i] = false;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	solve(0);

}
