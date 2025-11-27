#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

int solution(int n, int k)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		int cnt = 1;
		while (cnt != k)
		{
			++cnt;
			int value = q.front();
			q.pop();
			q.push(value);
		}
		q.pop();
	}

	return q.front();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int ret = solution(5, 2);
	cout << ret;
}

