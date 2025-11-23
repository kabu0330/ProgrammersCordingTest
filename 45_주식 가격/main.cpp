#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

vector<int> solution(vector<int> vec)
{
	vector<int> ret;


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

