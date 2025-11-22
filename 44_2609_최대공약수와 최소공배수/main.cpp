#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n, m;

int gcd(int a, int b)
{
	/*while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
	*/
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(int a, int b)
{
	return (long long)((a / gcd(a, b)) * b);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	cout << gcd(n, m) << "\n";
	cout << lcm(n, m) << "\n";
}

