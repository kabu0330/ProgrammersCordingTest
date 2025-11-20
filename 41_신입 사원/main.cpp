#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int t;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> vec;
		
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			vec.push_back({ a, b });
		}

		sort(vec.begin(), vec.end());
		
		int bestB = vec[0].second;
		int ret = 0;
		ret++;
		for (int i = 0; i < n; i++)
		{
			if (bestB > vec[i].second)
			{
				ret++;
				bestB = vec[i].second;
			}
		}
		cout << ret << endl;
	}

}

