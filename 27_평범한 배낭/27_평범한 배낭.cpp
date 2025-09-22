#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	vector<int> dp(k + 1, 0);

	int weight, value;
	for (int i = 0; i < n; ++i)
	{
		cin >> weight >> value;

		for (int j = k; j >= weight; --j)
		{
			// 무게에 맞춰 넣을 수 있는 최대치를 추적한다.
			int data = value + dp[j - weight];
			dp[j] = ::max(dp[j], value + dp[j - weight]);
		}
	}

	cout << dp[k] << endl;
}

