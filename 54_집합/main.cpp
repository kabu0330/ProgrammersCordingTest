#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
vector<bool> vec(21);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unsigned int bit_set = 0;

	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;

		int num;

		if (str == "add")
		{
			cin >> num;
			bit_set |= (1 << num);
		}
		else if (str == "remove")
		{
			cin >> num;
			bit_set &= ~(1 << num);
		}
		else if (str == "check")
		{
			cin >> num;
			if (bit_set & (1 << num))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (str == "toggle")
		{
			cin >> num;
			bit_set ^= (1 << num);
		}
		else if (str == "all")
		{
			bit_set = (1 << 21) - 1;
		}
		else if (str == "empty")
		{
			bit_set = 0;
		}
	}
}

