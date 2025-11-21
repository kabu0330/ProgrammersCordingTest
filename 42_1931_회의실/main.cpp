#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
vector<pair<int, int>> vec;
int ret = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		return a.second < b.second;
		});

	int end;
	end = vec[0].second;
	ret++;

	for (int i = 1; i < n; i++)
	{
		if (end <= vec[i].first)
		{
			ret++;
			end = vec[i].second;
		}
	}

	cout << ret << endl;

}

