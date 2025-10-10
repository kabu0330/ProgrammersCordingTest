
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1000001] = {};

int n, k;
int cnt = 0;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//    자신 동생
	cin >> n >> k;

	//    현재 위치, 시간
	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int next : {node + 1, node - 1, node * 2})
		{
			if (next < 0 || next >= 100001) continue;
			if (visited[next]) continue;
					
			visited[next] = visited[node] + 1;
			q.push(next);
		}
	}

	cout << visited[k] - 1;
}

