#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n, m, k;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true)
	{
		vector<int> vec(3);
		cin >> vec[0] >> vec[1] >> vec[2];
		
		if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0) break;

		::sort(vec.rbegin(), vec.rend());
		
		int a = vec[0];
		int b = vec[1];
		int c = vec[2];

		if (a * a == b * b + c * c)
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}

}

