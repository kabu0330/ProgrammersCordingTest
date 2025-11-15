#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	vector<int> times(n);
	for (int i = 0; i < n; i++)
	{
		cin >> times[i];
	}

	::sort(times.begin(), times.end());
	
	vector<int> dp(n);
	int cnt = times[0];
	for (int i = 1; i < times.size(); i++)
	{
		dp[i] = dp[i - 1] + times[i - 1];
		cnt += times[i] + dp[i];
	}
	
	cout << cnt;


}

