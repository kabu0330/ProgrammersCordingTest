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

	int cnt = 1;
	int cur = 1;
	for (size_t i = 0; i <= n; i++)
	{
		cur += i * 6;
		if (cur >= n)
		{
			break;
		}
		++cnt;
	}


	cout << cnt << endl;

}

