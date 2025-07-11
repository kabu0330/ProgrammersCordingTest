#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> adj(info.size());
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    int max_sheep = 0;

    // 1. 스택 정의: {양, 늑대, 다음 방문 가능 노드 목록}
    stack<tuple<int, int, vector<int>>> s;

    // 2. 초기 상태 Push
    vector<int> initial_next_nodes;
    for (int child : adj[0]) {
        initial_next_nodes.push_back(child);
    }
    s.push({ 1, 0, initial_next_nodes });

    // 3. 스택이 빌 때까지 반복
    while (!s.empty()) {
        // 4. 현재 상태를 스택에서 꺼내기
        auto [sheep, wolf, next_nodes] = s.top();
        s.pop();

        // 양이 잡아먹히면 이 경로는 더 이상 탐색하지 않음
        if (sheep <= wolf) {
            continue;
        }

        // 현재까지의 양 최대값 갱신
        max_sheep = max(max_sheep, sheep);

        // 다음 상태들을 만들어서 스택에 Push (재귀 호출 대체)
        for (int i = 0; i < next_nodes.size(); ++i) {
            int next_node = next_nodes[i];

            vector<int> new_next_nodes = next_nodes;
            new_next_nodes.erase(new_next_nodes.begin() + i);

            for (int child : adj[next_node]) {
                new_next_nodes.push_back(child);
            }

            if (info[next_node] == 0) { // 양인 경우
                s.push({ sheep + 1, wolf, new_next_nodes });
            }
            else { // 늑대인 경우
                s.push({ sheep, wolf + 1, new_next_nodes });
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
