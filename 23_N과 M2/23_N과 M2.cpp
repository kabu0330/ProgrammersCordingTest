#include <iostream>

using namespace std;

int n, m;
int arr[9] = {};
bool is_used[9] = { false };

void func(int k, int start)
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

	for (int i = start; i <= n; i++)
	{
		if (false == is_used[i])
		{
			arr[k] = i;
			is_used[i] = true;
			func(k + 1, i);
			is_used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	func(0, 1);
}
