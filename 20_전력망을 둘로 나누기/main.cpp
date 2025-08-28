#include <string>
#include <vector>
#include <climits>

using namespace std;

int dfs(int node, int parent, vector<vector<int>>& graph)
{
    int count = 1;
    for (int child : graph[node])
    {
        if (child != parent)
        {
            count += dfs(child, node, graph);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    for (const vector<int>& wire : wires)
    {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    int min_diff = INT_MAX;
    for (auto& wire : wires)
    {
        int a = wire[0];
        int b = wire[1];

        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

        int count_a = dfs(a, b, graph);
        int count_b = n - count_a;

        min_diff = ::min(min_diff, ::abs(count_a - count_b));
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return min_diff;
}

int main()
{
    int n = 9;
    vector<vector<int>> wires = { {1,3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    solution(n, wires);
}