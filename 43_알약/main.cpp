#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;

// 현재 상태
long long dp[34][34];

long long func(long long one, long long half)
{
	if (one < 0) return 0;
	if (half < 0) return 0; // 마이너스로 가지 않게 예외처리

	if (one == 0 && half == 0) return 1;

	long long& ret = dp[one][half];
	if (ret != -1) return dp[one][half];

	ret = 0;

	// 하나를 반을 쪼개 먹는 경우
	ret += func(one - 1, half + 1);

	// 반쪽짜리를 그냥 먹었다.
	ret += func(one, half - 1);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> n && n != 0)
	{
		::fill(&dp[0][0], &dp[0][0] + 34 * 34, -1);

		cout << func(n, 0) << endl;
	}

}

