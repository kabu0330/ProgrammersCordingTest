#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

vector<int> one = { 1, 2, 3, 4, 5 };
vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> vec)
{
	vector<int> ret;
	vector<int> matchCnt(3);
	
	for (int i = 0; i < vec.size(); i++)
	{
		if (one[i % one.size()] == vec[i])
		{
			matchCnt[0]++;
		}
		if (two[i % two.size()] == vec[i])
		{
			matchCnt[1]++;
		}
		if (three[i % three.size()] == vec[i])
		{
			matchCnt[2]++;
		}
	}

	// 최고점을 추출해서 비교하면 쉽다.
	int mn = *max_element(matchCnt.begin(), matchCnt.end());

	for (int i = 0; i < 3; i++)
	{
		if (matchCnt[i] == mn)
		{
			ret.push_back(i + 1);
		}
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

	vector<int> input = { 1, 2, 3, 4, 5 };


	vector<int> ret = solution(input);
}

