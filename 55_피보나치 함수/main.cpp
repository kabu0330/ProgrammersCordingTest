#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;

struct Count
{
	int zero = 0;
	int one = 0;
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	vector<Count> dp(41);

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i <= 40; i++)
	{
		dp[i].zero = dp[i - 1].zero + dp[i - 2].zero;
		dp[i].one = dp[i - 1].one + dp[i - 2].one;
	}

	while (n--)
	{
		int n;
		cin >> n;
		cout << dp[n].zero << ' ' << dp[n].one << endl;
	}

}

