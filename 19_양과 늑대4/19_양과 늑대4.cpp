
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

// 완전 탐색
int solution(vector<int> info, vector<vector<int>> edges) 
{
    vector<vector<int>> adj(info.size());
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    //          양, 늑대, 다음 노드 인덱스들
    stack<tuple<int, int, vector<int>>> route;
    int max_sheep = 1;

    route.push({ 1, 0, adj[0]});

    while (!route.empty())
    {
        auto [sheep, wolf, nodes] = route.top();
        route.pop();

        if (sheep <= wolf)
        {
            continue;
        }
        
        max_sheep = ::max(sheep, max_sheep);

        for (int i = 0; i < nodes.size(); i++)
        {
            int next_node = nodes[i];
            auto next_nodes = nodes; // 데이터 삭제할거라 복사
            next_nodes.erase(next_nodes.begin() + i); // 무한재귀 방지
            // 현재 노드를 제거하고 stack에 push함으로써 같은 노드를 또 탐색하지 않는다.

            // 자식 노드들 모두 추가
            for (int child : adj[next_node]) 
            {
                next_nodes.push_back(child);
            }

            // 양
            if (info[next_node] == 0)
            {
                route.push({ sheep + 1, wolf, next_nodes });
            }
            else // 늑대
            {
                route.push({ sheep, wolf + 1, next_nodes });
            }
            // 이 코드를 벗어나면 while 첫 조건문에서 늑대가 많은 경우의 수는
            // 모두 폐기처리
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

