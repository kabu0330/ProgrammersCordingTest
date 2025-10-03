
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int me,cousin;

vector<vector<int>> graph;
vector<int> visited;

bool dfs(int curNode, int depth, int& result)
{
	visited[curNode] = 1;

	if (curNode == cousin)
	{
		result = depth;
		return true;
	}
	
	for (const auto& adj : graph[curNode])
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

	//   사람, 나와 친척의 촌수, 간선 개수
	cin >> n >> me >> cousin >> m;

	graph.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		// 부모 자식
		int parent, child;
		cin >> parent >> child;

		graph[parent].push_back(child);
		graph[child].push_back(parent);
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

