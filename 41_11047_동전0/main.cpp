#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n, k;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	::sort(vec.rbegin(), vec.rend());

	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int coin = vec[i];
		int value = k / coin;
		cnt += value;
		k -= (value * coin);
		if (k <= 0)
		{
			break;
		}
	}


	cout << cnt;
}

