
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
vector<int> result;

unordered_map<int, vector<int>> adjList;

void bfs(int start)
{
	unordered_set<int> visited;
	queue<int> q;

	q.push(start);
	visited.insert(start);
	result.push_back(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int neighbor : adjList[node])
		{
			if (visited.find(neighbor) == visited.end())
			{
				q.push(neighbor);
				visited.insert(neighbor);		
				result.push_back(neighbor);
			}
		}
	}
}

vector<int> solution(vector<pair<int, int>> graph, int start)
{
	for (auto& edge : graph)
	{
		int u = edge.first;
		int v = edge.second;
		adjList[u].push_back(v);
	}

	bfs(start);
	return result;
}

int main()
{
	vector<pair<int, int>> graph = {
		{1, 2},
		{1, 3},
		{2, 4},
		{2, 5},
		{3, 6},
		{3, 7},
		{4, 8},
		{5, 8},
		{6, 9},
		{7, 9}
	};
	int start = 1;
	vector<int> result = solution(graph, start);
}

