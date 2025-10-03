#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9] = {};
bool isUsed[9] = {};

void backtrack(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			arr[k] = i;
			backtrack(k + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	backtrack(0);
}
