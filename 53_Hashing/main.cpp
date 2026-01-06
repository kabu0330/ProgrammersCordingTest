#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int r = 31;
	const int m = 1234567891;

	cin >> n;
	string str;
	cin >> str;

	long long total = 0;
	long long rPow = 1;
	for (int i = 0; i < n; i++)
	{
		int value = str[i] - 'a' + 1;
		total = (total + (value * rPow)) % m;
		rPow = (rPow * r) % m;
	}

	cout << total << endl;

}

