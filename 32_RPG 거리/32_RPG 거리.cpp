
#include <iostream>
#include <vector>

using namespace std;

enum Color
{
	red,
	green,
	blue
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<vector<int>> dp(n + 1, vector<int>(3));
	vector<vector<int>> cost(n + 1, vector<int>(3));

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i][red] >> cost[i][green] >> cost[i][blue];
	}
	
	dp[1][0] = cost[1][red]; // Red
	dp[1][1] = cost[1][green]; // Green
	dp[1][2] = cost[1][blue]; // Blue

	// 연속된 열을 제외한 최소값과 누적된 비용의 합
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int min_cost = min({ dp[n][0], dp[n][1], dp[n][2] });
	cout << min_cost;
	
}

