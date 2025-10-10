#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
int visited[1001] = {};

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
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++cnt;
			bfs(i);
		}
	}

	cout << cnt;
}
