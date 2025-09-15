#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// 거리, 노드
using Node = std::pair<int, int>;

int v, e, k;
priority_queue<Node, vector<Node>, greater<Node>> heap;
vector<int> dist;
vector<vector<Node>> edges;

void solve()
{
	dist[k] = 0;
	heap.push({ 0, k });

	while (heap.empty() == false)
	{
		int cost = heap.top().first;
		int cur_node = heap.top().second;
		heap.pop();

		if (dist[cur_node] < cost)
		{
			continue;
		}

		for (const auto& pair : edges[cur_node])
		{
			int total_cost = pair.first + cost;
			int next_node = pair.second;

			int cur_cost = dist[next_node];
			if (total_cost < cur_cost)
			{
				dist[next_node] = total_cost;
				heap.push({ total_cost, next_node });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> k;
	dist.resize(v + 1, INT_MAX);
	edges.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int u, v_node, w;
		cin >> u >> v_node >> w;
		edges[u].push_back({w, v_node });
	}

	solve();

	for (int i = 1; i < dist.size(); i++)
	{
		if (dist[i] == INT_MAX)
		{
			cout << "INF" << "\n";
			continue;
		}

		cout << dist[i] << "\n";
	}
}

