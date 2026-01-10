#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
int token = 0;

void dfs(int value, int target)
{
	if (target == value)
	{
		token += 1;
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (value + i <= target)
		{
			value += i;
			dfs(value, target);
			value -= i;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--)
	{
		int value;
		cin >> value;
		dfs(0, value);
		cout << token << endl;
		token = 0;
	}

}

