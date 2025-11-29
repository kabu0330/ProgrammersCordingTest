#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <numeric>

#define endl '\n'

using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
	vector<vector<pair<int, int>>> graph(N + 1);
	for (int i = 0; i < road.size(); i++)
	{
		int u = road[i][0];
		int v = road[i][1];
		int w = road[i][2];
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	vector<int> dist(N + 1, INT_MAX);
	// 비용, 노드 순
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair( 0, 1 ));
	dist[1] = 0;

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (auto pr : graph[curNode])
		{
			int nextNode = pr.first;
			int nextDist = pr.second;
			
			if (nextNode == 1) continue;
			if (dist[nextNode] > nextDist + curDist)
			{
				dist[nextNode] = curDist + nextDist;
				pq.push(make_pair(dist[nextNode], nextNode));
			}

		}
	}

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

