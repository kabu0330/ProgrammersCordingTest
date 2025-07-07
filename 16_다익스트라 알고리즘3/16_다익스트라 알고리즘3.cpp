#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

vector<int> solution(
    int start,
    int numNodes,
    const vector<tuple<int, int, int>>& edges)
{
    // 1. 그래프 지도를 만든다.
    // 노드 : vector<인접 노드, 거리>
    vector<vector<pair<int, int>>> adj(numNodes);
    for (const auto& [from, to, weight] : edges)
    {
        adj[from].emplace_back(to, weight);
    }

    // 2. 다익스트라는 최단 경로를 구하기 때문에 초기화는 최댓값으로 한다.
    const int INF = numeric_limits<int>::max();
    
    // 3. 최단 경로 <= Min Heap == priority_queue
    // 기준 : 거리
    //            거리, 노드 인덱스, 3번째 인자 지정을 위해,      최소값 기준 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    
    // 4. 최단 거리만 기록할 컨테이너
    // 최소값을 기록해야 할 자료구조이므로 초기화는 최댓값으로
    vector<int> distances(numNodes, INF);

    // 5. 시작 노드 설정
    heap.emplace(0, start);
    distances[start] = 0; // 시작 노드의 거리는 0

    while (false == heap.empty())
    {
        int cur_node = heap.top().second;
        int cost = heap.top().first;
        heap.pop();
        
        // 10. 현재 이동경로가 최단 경로가 아니야?
        if (distances[cur_node] < cost)
        {   // 응. 더 긴 경로야.
            continue; // 그럼 Pass
        }

        // 6. 현재 노드와 인접한 노드들을 탐색한다.
        for (const pair<int, int>& edge : adj[cur_node])
        {
            int adj_node = edge.first;
            int total_cost = edge.second + cost; // 거리 = 현재까지 "누적" 거리

            // 7. 지금까지 이동한 경로가 최단거리였나?
            if (total_cost < distances[adj_node])
            {
                // 8. 최단 거리 갱신 후
                distances[adj_node] = total_cost;

                // 9. 인접 경로 추가. 
                // why? 최단 거리로 왔으니 
                // 인접 노드에서 다른 노드로 이동이 최단 경로일 확률이 높다.
                heap.emplace(total_cost, adj_node);
            }
        }
    }
    
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
