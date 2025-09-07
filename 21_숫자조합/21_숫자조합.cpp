
#include <iostream>
#include <vector>

using namespace std;
vector<int> vec;

void recursive(int start, int max, vector<int>& vec, vector<vector<int>>& result)
{
	int nums = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		nums += vec[i];
		if (nums > 10)
		{
			return;
		}
	}
	if (nums == 10)
	{
		result.push_back(vec);
		return;
	}

	for (int i = start; i <= max; i++)
	{
		vec.push_back(i);
		recursive(i + 1, max, vec, result);
		vec.pop_back();
	}
}

vector<vector<int>> solution(int n)
{
	vector<vector<int>> result;

	recursive(1, n, vec, result);

	return result;
}

int main()
{
	int n = 7;
	vector<vector<int>> result = solution(n);
}
