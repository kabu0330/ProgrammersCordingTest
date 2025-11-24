#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define endl '\n'

using namespace std;

bool solution(vector<int> vec, int target)
{
	vector<int> hash(target + 1);
	//unordered_set<int> hash;
	for (int i = 0; i < vec.size(); i++)
	{
		hash[vec[i]] = true;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		int num = target - vec[i];

		if (vec[i] == num)
		{
			continue;
		}
		if (num < 0)
		{
			continue;
		}
		if (hash[num])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> input = { 2, 3, 5, 9 };


	bool ret = solution(input, 10);
	cout << ret;
}

