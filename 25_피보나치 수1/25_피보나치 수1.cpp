#include <iostream>
#include <vector>

using namespace std;

int recusion_count = 0;

int fibo(int n)
{
	if (n <= 1)
	{
		return n;
	}

	++recusion_count;
	return fibo(n - 1) + fibo(n - 2);
}

int fibonacci(int n)
{
	int dp_count = 0;
	vector<int> dp;
	dp.resize(n + 1);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		++dp_count;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp_count;
}

int main()
{
	int n;
	cin >> n;

	cout << fibo(n) << " ";

	cout << fibonacci(n);	
}

