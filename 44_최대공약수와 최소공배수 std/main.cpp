#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#define endl '\n'

using namespace std;

// 전역 변수
int n, m;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	cout << gcd(n, m) << endl;
	cout << std::lcm(n, m);

}

