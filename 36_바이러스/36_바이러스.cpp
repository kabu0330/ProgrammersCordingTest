#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph = {};
int visited[101] = {};
int cnt = 0;

void bfs(int start)
{
	queue<int> q;

	q.push(start);
	visited[start] = true;
	
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (const auto& adj : graph[node])
		{
			if (!visited[adj])
			{
				visited[adj] = true;
				q.push(adj);
				++cnt;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// n : 컴퓨터의 수
	// m : 노드 연결 수
	cin >> n >> m;

	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);
	
	cout << cnt;
}

