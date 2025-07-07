#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

// 이 함수 내부를 직접 구현해보세요.
vector<int> solution(
    int start,
    int numNodes,
    const vector<tuple<int, int, int>>& edges
) {
    // 1. 시작점으로부터 각 노드까지의 최단 거리를 저장할 컨테이너를 만든다.
    //    초기값은 연결되지 않음을 의미하는 무한대(INF)로 설정한다.
    const int INF = numeric_limits<int>::max();


    // 2. 그래프를 표현할 자료구조를 만든다. (인접 리스트 방식 추천)
    //    예시: vector<pair<int, int>> adj[numNodes];
    //    adj[A] = { {B, 가중치}, {C, 가중치} }; -> A에서 B, C로 가는 간선 정보
    //    입력으로 주어진 edges를 순회하며 그래프 정보를 채운다.
    vector<vector<pair<int, int>>> adj(numNodes);
    for (const auto& [from, to, weight] : edges)
    {
        adj[from].push_back({ to, weight });
    }


    // 3. 다익스트라 알고리즘의 핵심인 우선순위 큐(Min Heap)를 생성한다.
    //    큐에는 {거리, 노드 번호} 쌍을 저장하여, 거리가 가장 짧은 노드가
    //    항상 맨 위에 오도록 설정해야 한다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<int> distances(numNodes, INF);

    // 4. 시작 노드의 거리를 0으로 설정하고, 우선순위 큐에 {0, 시작 노드}를 추가한다.
    heap.emplace(0, start);
    distances[start] = 0;

    // 5. 우선순위 큐가 빌 때까지 아래 과정을 반복하는 while 루프를 시작한다.
    //    while (!pq.empty()) { ... }
    while (!heap.empty())
    {
        // 6. 루프 안에서, 우선순위 큐의 top에서 현재 가장 가까운 노드 정보를 꺼낸다.
        //    (현재까지의 최단 거리, 현재 노드 번호)
        int cost = heap.top().first;
        int here = heap.top().second;
        heap.pop();

        // 7. (최적화) 만약 큐에서 꺼낸 거리 정보가 이미 기록된 최단 거리보다 크다면,
        //    더 짧은 경로를 이전에 발견한 것이므로 건너뛴다. (continue)
        if (distances[here] < cost)
        {
            continue;
        }

        // 8. 현재 노드와 연결된 모든 이웃 노드를 순회한다.
        for (const pair<int, int>& edge : adj[here])
        {
            // 9. 이웃 노드에 대해, 현재 노드를 거쳐가는 새로운 경로의 거리를 계산한다.
            //    (새로운 거리 = 현재 노드까지의 최단 거리 + 이웃 노드까지의 가중치)
            int there = edge.first;
            int next_cost = edge.second + cost;
            
            // 10. 만약 새로운 경로가 기존에 기록된 거리보다 짧다면,
            //     이웃 노드의 거리를 새로운 거리로 업데이트하고,
            //     우선순위 큐에 {새로운 거리, 이웃 노드} 정보를 추가한다.
            int origin_cost = distances[there];
            if (next_cost < origin_cost) // 기존 값보다 이번 값이 더 작으면
            {
                distances[there] = next_cost;
                heap.emplace(next_cost, there);
            }

        }
    }
    // 11. while 루프가 끝나면, 1번에서 만들었던 거리 정보 컨테이너를 반환한다.
    return distances;
}

int main()
{
    // 테스트용 데이터
    int start = 0;
    int numNodes = 3;
    vector<tuple<int, int, int>> edges = {
        {0, 1, 9}, {0, 2, 3}, {1, 0, 5}, {2, 1, 1}
    };

    // solution 함수 호출
    vector<int> result = solution(start, numNodes, edges);

    // 결과 출력
    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < numNodes; ++i)
    {
        cout << "Node " << i << ": ";
        if (result[i] == numeric_limits<int>::max())
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << result[i] << endl;
        }
    }

    return 0;
}