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
	int cnt = 0;
	vector<bool> vec(n + 1, true);
	
	for (int i = 2; i <= n; i++)
	{
		if (vec[i] == false) // 이미 배수였던 수는 소수가 아니므로 탐색하지 않는다.
		{
			continue;
		}

		for (int j = i; j <= n; j += i) // 배수로 움직일 것이므로 다음 탐색은 더하면서 이동한다.
		{
			if (j % i == 0)
			{
				if (vec[j])
				{
					vec[j] = false;
					++cnt;
					if (cnt == k)
					{
						cout << j << endl;
						return 0;
					}
				}
			}
		}
	}

}

