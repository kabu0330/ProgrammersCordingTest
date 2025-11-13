#include <iostream>

using namespace std;

int n, m;
int arr[10] = {};
int used[10] = {};

void backtracking(int start, int k)
{
	if (k == m)
	{
		for (int i = 0; i < k; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		if (used[i] == false)
		{
			used[i] = true;
			arr[k] = i;
			backtracking(i + 1, k + 1);
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

	backtracking(1, 0);

}

