#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;

bool isPrime(int num)
{
	if (num < 2) return false;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	int cnt = 0;
	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (isPrime(a))
		{
			++cnt;
		}
	}

	cout << cnt << endl;
}

