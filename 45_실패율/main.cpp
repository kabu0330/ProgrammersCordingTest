#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

vector<int> solution(int n, vector<int> vec)
{
	vector<int> ret;
	// 실패율 : 스테이지 도달, 클리어 못함 / 스테이지 도달한 수
	vector<double> fail(n + 2);
	
	for (int ele : vec)
	{
		fail[ele]++;
	}

	vector<pair<int, double>> failRatio(n);
	int total = vec.size();
	for (int i = 0; i < n; i++)
	{
		failRatio[i].first = i + 1;
		if (total == 0)
		{
			failRatio[i].second = 0;
		}
		else
		{
			failRatio[i].second = fail[i + 1] / total;
		}
		total -= fail[i + 1];
	}

	sort(failRatio.begin(), failRatio.end(), [](pair<int, double> a, pair<int, double> b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second > b.second;
		});

	for (const auto& ele : failRatio)
	{
		ret.push_back(ele.first);
	}

	for (auto& ele : ret)
	{
		cout << ele << " ";
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> input = { 2, 1, 2, 6, 2, 4, 3, 3};
	int n = 5;

	vector<int> ret = solution(n, input);
}

