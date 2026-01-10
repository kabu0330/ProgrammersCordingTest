#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n, m;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	vector<int> vec(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int value;
		cin >> value;
		vec[i] = vec[i - 1] + value;
	}

	while (m--)
	{
		int start, end;
		cin >> start >> end;
		
		int ret = vec[end] - vec[start - 1];

		cout << ret << endl;
	}

}

