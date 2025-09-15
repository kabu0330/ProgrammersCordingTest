
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r;
vector<vector<int>> graph;

vector<int> visit_order;


void bfs(int cur_node)
{
	queue<int> q;

	q.push(cur_node);
	visit_order[cur_node] = 1;
	int count_order = 2;

	while (false == q.empty())
	{
		int node = q.front();
		q.pop();

		for (int next_node : graph[node])
		{
			if (visit_order[next_node] == 0)
			{
				visit_order[next_node] = count_order++;
				q.push(next_node);
			}
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
		std::sort(vec.begin(), vec.end());
	}

	bfs(r);

	for (int i = 1; i < visit_order.size(); i++)
	{
		cout << visit_order[i] << "\n";
	}
}

