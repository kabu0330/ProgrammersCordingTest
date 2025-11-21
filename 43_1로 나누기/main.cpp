#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
int dp[1000004];

int func(int x)
{
	if (x == 1) return 0;
	if (dp[x]) return dp[x];

	int ret = 0;
	ret = func(x - 1) + 1;
	if (x % 3 == 0)
	{
		ret = ::min(ret, func(x / 3) + 1);
	}
	if (x % 2 == 0)
	{
		ret = ::min(ret, func(x / 2) + 1);
	}

	return dp[x] = ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	cout << func(n);
}

