#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


#define endl '\n'

using namespace std;

// 전역 변수
long long a, b, c;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true)
	{
		vector<int> vec(3);
		for (int i = 0; i < 3; i++)
		{
			cin >> vec[i];
		}
		if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0)
		{
			break;
		}

		sort(vec.rbegin(), vec.rend());

		if (pow(vec[0], 2) == ::pow(vec[1], 2) + pow(vec[2], 2))
		{
			cout << "right" << "\n";
		}
		else
		{
			cout << "wrong" << "\n";
		}
	}


}

