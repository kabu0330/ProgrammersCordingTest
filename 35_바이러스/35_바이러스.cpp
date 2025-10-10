
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int cnt = 0;

void bfs(int node)
{   
    queue<int> q;
    q.push(node);

    visited[node] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (const auto& adj : graph[curNode])
        {
            if (!visited[adj])
            {
                ++cnt;
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    cout << cnt;

}
