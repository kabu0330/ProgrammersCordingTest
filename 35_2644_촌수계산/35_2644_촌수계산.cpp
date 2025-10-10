
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int n, me, cousin, m ;
vector<vector<int>> tree;
vector<bool> visited;

bool dfs(int node, int depth, int& result)
{
	visited[node] = true;

	if (node == cousin)
	{
		result = depth;
		return true;
	}
	
	for (const auto& adj : tree[node])
	{
		if (!visited[adj])
		{
			if (dfs(adj, depth + 1, result))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> me >> cousin >> m;

	tree.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int parent, child;
		cin >> parent >> child;
		tree[parent].push_back(child);
		tree[child].push_back(parent);
	}
	
	int result = -1;
	if (dfs(me, 0, result))
	{
		cout << result;
	}
	else
	{
		cout << -1;
	}
}
