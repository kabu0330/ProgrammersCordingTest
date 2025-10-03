
#include <iostream>
#include <vector>

using namespace std;

/* 점화식이 피보나치 수열과 같다.
*  dp[1] = 1;
*  dp[2] = 2;
*  dp[3] = 1 + 2 = 3;
*  dp[4] = 3 + 2 = 5;
*  dp[5] = 5 + 3 = 8; 
*  ...
*/

int main()
{
	int n;
	cin >> n;

	if (n <= 2)
	{
		cout << n;
		return 0;
	}

	vector<int> dp(n + 1);
	
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n];
}
