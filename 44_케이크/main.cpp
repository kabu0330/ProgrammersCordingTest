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

	vector<bool> vec(n + 1, false);
	int current = 1;
	int count = 0;

	while (count < n - 2)
	{
		if (!vec[current])
		{
			vec[current] = true;
			count++;

			int skip = 0;
			while (skip < k)
			{
				current++;
				if (current > n) current = 1;
				if (!vec[current]) ++skip;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vec[i]) cout << i << " ";
	}
}

