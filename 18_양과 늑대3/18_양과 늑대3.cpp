#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) 
{
    vector<vector<int>> adj(info.size());
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    int max_sheep = 0;

	stack<tuple<int, int, vector<int>>> stk;
    
    vector<int> init_child;
    for (int i = 0; i < adj[0].size(); i++)
    {
        init_child.push_back(adj[0][i]);
    }

    stk.push({ 1, 0, init_child });

    while (!stk.empty()) 
    {
        auto [sheep, wolf, nodes] = stk.top();
        stk.pop();

        if (sheep <= wolf)
        {
            continue;
        }

        max_sheep = ::max(max_sheep, sheep);

        for (int i = 0; i < nodes.size(); i++)
        {
            int next_node = nodes[i];
            vector<int> next_nodes = nodes;
            next_nodes.erase(next_nodes.begin() + i);

            for (int child : adj[next_node])
            {
                next_nodes.push_back(child);
            }

            if (info[next_node] == 0)
            {
                stk.push({ sheep + 1, wolf, next_nodes });
            }
            else
            {
                stk.push({ sheep, wolf + 1, next_nodes });
            }
        }
    }

    return max_sheep;
}

int main()
{
    vector<int> info = { 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 };
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9} };

    int result = solution(info, edges);
}
