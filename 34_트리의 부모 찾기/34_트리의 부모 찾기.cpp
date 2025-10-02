#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parents;

void dfs(int start)
{
	visited[start] = true;
	
	for (const auto& adj : graph[start])
	{
		if (!visited[adj])
		{
			parents[adj] = start;
			dfs(adj);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	
	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();

		visited[curNode] = true;

		for (int adj : graph[curNode])
		{
			if (!visited[adj])
			{
				parents[adj] = curNode;
				q.push(adj);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	graph.resize(n + 1);
	visited.resize(n + 1);
	parents.resize(n + 1);

	for (int i = 0; i < n -1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);	
	}

	//dfs(1);
	bfs(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parents[i] << '\n';
	}
}
