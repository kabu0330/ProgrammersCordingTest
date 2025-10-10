
#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int index, int sum)
{
	if (index == numbers.size())
	{
		return sum == target ? 1 : 0;
	}

	int count = 0;
	count += dfs(numbers, target, index + 1, sum + numbers[index]);
	count += dfs(numbers, target, index + 1, sum - numbers[index]);

	return count;
}

int solution(vector<int> numbers, int target)
{
	return dfs(numbers, target, 0, 0);
}

int main()
{
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;

	int result = solution(numbers, target);

	int a = 0;
}

