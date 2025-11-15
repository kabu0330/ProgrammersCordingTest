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

	int cnt = 0;
	while (n >= 0)
	{
		if (n % 5 == 0)
		{
			cnt += n / 5;
			cout << cnt;
			return 0;
		}

		n -= 3;
		++cnt;
	}

	cout << -1;

}

