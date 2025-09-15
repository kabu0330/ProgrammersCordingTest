
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, r;
vector<vector<int>> graph;
vector<int> visit_order;
int order_count = 1;

void dfs(int cur_node)
{
    visit_order[cur_node] = order_count++;

    for (int node : graph[cur_node])
    {
        if (visit_order[node] == 0)
        {
            dfs(node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;

    graph.resize(m + 1);
    visit_order.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto& inner_vec : graph)
    {
        std::sort(inner_vec.begin(), inner_vec.end());
    }
    
    dfs(r);

    for (int i = 1; i < visit_order.size(); i++)
    {
        cout << visit_order[i] << "\n";
    }
}
