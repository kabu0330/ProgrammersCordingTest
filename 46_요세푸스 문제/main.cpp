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

	for (int i = 0; i < n - 1; i++)
	{
		int cnt = k - 1;
		while (cnt > 0)
		{
			int front = q.front();
			q.pop();
			q.push(front);
			--cnt;
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

