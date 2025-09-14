
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int fibo(int n)
{
	if (n <= 1)
	{
		return n;
	}

	if (dp[n] != -1)
	{
		return dp[n];
	}

	dp[n] = fibo(n - 1) + fibo(n - 2);

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n <= 1)
	{
		cout << n;
		return 0;
	}

	dp.assign(n + 1, -1);

	cout << fibo(n);
}

