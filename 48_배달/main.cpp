#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


#define endl '\n'

using namespace std;

// 노드, 거리
vector<vector<pair<int, int>>> graph;
vector<int> dist;
void dfs(int node, int k)
{
	for (auto pr : graph[node])
	{
		if (pr.first == 1) continue;
		if (dist[pr.first] < dist[node] + pr.second) continue;

		dist[pr.first] = dist[node] + pr.second;
		dfs(pr.first, k);
	}
	
}

int solution(int N, vector<vector<int>> road, int K)
{
	graph.resize(N + 1);
	for (int i = 0; i < road.size(); i++)
	{
		int start = road[i][0];
		int end = road[i][1];
		int cost = road[i][2];
		
		graph[start].push_back({ end, cost });
		graph[end].push_back({ start, cost });
	}

	dist.resize(N + 1, INT_MAX);
	dist[1] = 0;
	
	dfs(1, K);

	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] <= K) ++ret;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n = 5;
	int k = 3;
	vector<vector<int>> road = { {1, 2,1}, {2,3,3}, {5,2,2}, {1,4,2},{5,3,1},{5,4,2} };
	

	int ret = solution(n, road, k);

	cout << ret;
}

