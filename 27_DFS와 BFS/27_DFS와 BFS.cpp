
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, start;
vector<vector<int>> graph;
vector<int> dfs_visited;
vector<int> bfs_visited;

void dfs(int cur_node)
{
	if (dfs_visited[cur_node] == 1)
	{
		return;
	}

	dfs_visited[cur_node] = 1;
	cout << cur_node << " ";
	
	for (auto& adj_node : graph[cur_node])
	{
		if (dfs_visited[adj_node] == 0)
		{		
			dfs(adj_node);
		}
	}
}

void bfs()
{
	bfs_visited.resize(n + 1);

	queue<int> q;
	q.push(start);
	bfs_visited[start] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		cout << node << " ";

		for (auto& adj_node : graph[node])
		{
			if (bfs_visited[adj_node] == 0)
			{
				bfs_visited[adj_node] = 1;
				q.push(adj_node);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> start;

	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int k, w;
		cin >> k >> w;
		graph[k].push_back(w);
		graph[w].push_back(k);
	}

	for (auto& vec : graph)
	{
		std::sort(vec.begin(), vec.end());
	}

	dfs_visited.resize(n + 1);
	dfs(start);
	cout << "\n";
	bfs();
}
