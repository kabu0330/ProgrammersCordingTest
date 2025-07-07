
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        fill_n(graph[i], MAX_NODES, INF);
        visited[i] = false;
    }

    for (const auto& [from, to, weight] : edges)
    {
        graph[from][to] = weight;
    }

    vector<int> distances(numNodes, INF);
    distances[start] = 0;

    for (int i = 0; i < numNodes - 1; i++)
    {
        int minDistance = INF;
        int closesNode = -1;
        for (int j = 0; j < numNodes; j++)
        {
            if (!visited[j] && distances[j] < minDistance)
            {
                minDistance = distances[j];
                closesNode = j;
            }
        }

        visited[closesNode] = true;

        for (int j = 0; j < numNodes; j++)
        {
            int newDistance = distances[closesNode] + graph[closesNode][j];
            if (!visited[j] && graph[closesNode][j] != INF && newDistance < distances[j])
            {
                distances[j] = newDistance;
            }
        }
    }

    return distances;
}

int main()
{
    int start = 0;
    int numNodes = 3;
    vector<tuple<int, int, int>> edges = { {0, 1, 9}, {0, 2, 3}, {1, 0, 5}, {2, 1, 1} };
    vector<int> result = solution(start, numNodes, edges);
}

