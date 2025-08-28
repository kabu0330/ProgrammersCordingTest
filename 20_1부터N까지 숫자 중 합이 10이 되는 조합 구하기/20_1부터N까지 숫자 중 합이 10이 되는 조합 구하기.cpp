#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int num, int sum, int start)
{
	if (sum == 10)
	{
		results.push_back(selected_nums);
		return;
	}
	for (int i = start; i <= num; ++i)
	{
		if (sum + i <= 10)
		{
			selected_nums.push_back(i);
			backtrack(num, sum + i, i + 1);
			selected_nums.pop_back();
		}
	}
}

vector<vector<int>> solution(int n)
{
	backtrack(n, 0, 1);

	return results;
}

int main()
{
	int n = 5;
	solution(n);
}
