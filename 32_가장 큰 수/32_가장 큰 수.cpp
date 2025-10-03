
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
	vector<string> strs;
	for (const auto& num : numbers)
	{
		strs.push_back(to_string(num));
	}

	sort(strs.begin(), strs.end(), [](const string& left, const string& right) {
		return left + right > right + left;
		});

	string answer = {};
	for (const auto& str : strs)
	{
		answer += str;
	}
	return answer;
}

int main()
{
	solution({ 6, 10, 2 });
}
