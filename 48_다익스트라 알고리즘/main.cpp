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
#include <tuple>

#define endl '\n'

using namespace std;

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
	const int INF = INT_MAX;
	
	vector<vector<pair<int, int>>> graph(numNodes);
	for (const auto& [from, to, weight] : edges)
	{
		graph[from].emplace_back(to, weight);
	}

	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curDist > distances[curNode]) continue;

		for (const auto& [next, weight] : graph[curNode])
		{
			int newDist = distances[curNode] + weight;
			if (newDist < distances[next])
			{
				distances[next] = newDist;
				pq.push({ newDist, next });
			}
		}
	}

	return distances;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int start = 0;
	int numNodes = 3;
	vector<tuple<int, int, int>> edges = { {0, 1, 9}, {0, 2, 3}, {1, 0, 5}, {2, 1, 1} };

	vector<int> ret = solution(start, numNodes, edges);

	for (auto& ele : ret)
	{
		cout << ele << " ";
	}
}

