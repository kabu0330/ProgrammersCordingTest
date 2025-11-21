#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;

int dp[50] = {};

int fibo(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (dp[n]) return dp[n];

	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	cout << fibo(n);


}

