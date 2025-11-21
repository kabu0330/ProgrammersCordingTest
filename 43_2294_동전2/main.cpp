#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>


#define endl '\n'

using namespace std;

// 전역 변수
int n, k;
vector<int> dp;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	const int INF = k + 1;
	dp.assign(k + 1, INF);

	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		for (int j = temp; j <= k; j++)
		{
			dp[j] = ::min(dp[j - temp] + 1, dp[j]);
		}
	}

	if (dp[k] == INF)
	{
		cout << "-1";
	}
	else
	{
		cout << dp[k];
	}
}

