
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> result;

void solve()
{
	queue<int> q;
	q.push(1);
	visited.resize(n + 1);
	visited[1] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto& adj_node : graph[node])
		{
			if (visited[adj_node] == 0)
			{
				visited[adj_node] = 1;
				q.push(adj_node);
				result.push_back(adj_node);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int k, w;
		cin >> k >> w;
		graph[k].push_back(w);
		graph[w].push_back(k);
	}
	
	solve();

	cout << result.size();
}

