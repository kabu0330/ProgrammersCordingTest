#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;

vector<int> a;
vector<int> b;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	
	a.resize(n);
	b.resize(n);
	for (int j = 0; j < n; j++)
	{
		cin >> a[j];
	}
	for (int j = 0; j < n; j++)
	{
		cin >> b[j];
	}
	
	::sort(a.begin(), a.end());
	::sort(b.rbegin(), b.rend());

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += a[i] * b[i];
	}


	cout << result;


}

