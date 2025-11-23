#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define endl '\n'

using namespace std;


vector<int> solution(vector<int> numbers)
{
	set<int> s;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			s.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> ret;
	for (auto& ele : s)
	{
		ret.push_back(ele);
		//cout << ele << " ";
	}
	return ret;
}

int main()
{
	vector<int> numbers = { 2, 1, 3, 4, 1 };
	vector<int> result = solution(numbers);
}

