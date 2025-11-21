#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
long long dist[100004];
long long price[100004];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}

	long long sum = 0;
	long long mnPrice = 0;

	sum = price[0] * dist[1];
	mnPrice = price[0];

	for (int i = 1; i < n; i++)
	{
		if (mnPrice > price[i])
		{
			mnPrice = price[i];
		}
		sum += mnPrice * dist[i + 1];
	}

	cout << sum;
}

