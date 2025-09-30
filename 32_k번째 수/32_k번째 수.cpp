
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> result;
	vector<int> subArray;
	for (const auto& cmd : commands)
	{
		subArray.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
		sort(subArray.begin(), subArray.end());
		result.push_back(subArray[cmd[2] - 1]);
	}
	return result;
}

int main()
{
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
	vector<int> result = solution(array, commands);
}
