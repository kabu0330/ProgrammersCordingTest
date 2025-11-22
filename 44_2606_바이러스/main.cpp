#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

// 전역 변수
int n, m;
vector<vector<int>> graph;
int visited[104];

int bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int ret = 0;
	
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		
		for (auto& adj : graph[node])
		{
			if (visited[adj] == false)
			{
				visited[adj] = true;
				++ret;
				q.push(adj);
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(1);


}

