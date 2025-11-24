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
		// num 값 이상인 첫번째 위치
		auto pos = lower_bound(vec.begin(), vec.end(), num);

		// 존재하지 않으면 추가
		if (pos == vec.end())
		{
			vec.push_back(num); 
		}
		else
		{
			*pos = num; // 더 작은 값으로 바꿔버린다.
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

