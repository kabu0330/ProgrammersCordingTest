#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
int dp[304];

vector<int> vec;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		vec.push_back(c);
	}

	// 점화식 : 앞의 결과를 이용해서 점차 변화하는 식
	// DP는 앞의 결과를 미리 넣어줘야 한다.

	dp[1] = vec[0];
	dp[2] = vec[0] + vec[1];
	dp[3] = ::max(vec[0] + vec[2], vec[1] + vec[2]);
	
	for (int i = 4; i <= n; i++)
	{
		dp[i] = ::max(dp[i - 2] + vec[i - 1], dp[i - 3] + vec[i - 2] + vec[i - 1]);
	}

	cout << dp[n];
}

