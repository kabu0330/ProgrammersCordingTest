#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n, k;
int dp[10004];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		for (int j = c; j <= k; j++)
		{
			dp[j] += dp[j - c];
		}
	}

	cout << dp[k] << endl;

}

