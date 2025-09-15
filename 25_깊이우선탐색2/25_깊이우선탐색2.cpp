
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<vector<int>> graph;
vector<int> visit_order;
int count_order = 1;

void dfs(int cur_node)
{
	visit_order[cur_node] = count_order++;

	for (int next_node : graph[cur_node])
	{
		if (visit_order[next_node] == 0)
		{
			dfs(next_node);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> r;
	
	graph.resize(m + 1);
	visit_order.resize(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (auto& vec : graph)
	{
		std::sort(vec.begin(), vec.end(), std::greater<>());
	}
	
	dfs(r);

	for (int i = 1; i < visit_order.size(); i++)
	{
		cout << visit_order[i] << "\n";
	}
}

