#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

int solution(vector<int> nums)
{

	vector<int> vec;
	
	for (int num : nums)
	{
		auto pos = lower_bound(vec.begin(), vec.end(), num);
		
		if (pos == vec.end())
		{
			vec.push_back(num);
		}
		else
		{
			*pos = num;
		}

	}

	return vec.size();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> input = { 1, 4, 2, 3, 1, 5, 7, 3 };


	int ret = solution(input);
	cout << ret;
}

