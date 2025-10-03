
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int cnt = 0;

void dfs(int start)
{
	visited[start] = 1;
	
	for (int adj : graph[start])
	{
		if (!visited[adj])
		{
			++cnt;
			dfs(adj);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << cnt;
}

