#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

// long long으로 INF를 설정하여 오버플로우/언더플로우 방지
const long long INF = numeric_limits<long long>::max();

// 반환값: {음수 사이클 존재 여부, 최단 거리 배열}
pair<bool, vector<long long>> bellman_ford(
    int start,
    int numNodes,
    const vector<tuple<int, int, int>>& edges
) {
    // 1. 최단 거리 배열 선언 및 초기화
    vector<long long> distances(numNodes, INF);
    distances[start] = 0;

    // 2. 메인 루프: (V - 1)번 반복
    for (int i = 0; i < numNodes - 1; ++i) {
         bool updated = false; // 최적화를 위한 플래그

        // 3. 모든 간선(E개)을 순회하며 거리 갱신 (Relaxation)
        for (const auto& edge : edges) {
            int from, to, weight;
            tie(from, to, weight) = edge;

            long long cur_distance = distances[from];
            long long next_distance = distances[to];
            long long total_distance = distances[from] + weight;

            // 시작점(from)에 도달 가능한 경우에만 갱신 시도
            if (cur_distance != INF &&
                next_distance > total_distance)
            {
                distances[to] = total_distance;
                updated = true;
            }
        }

        // 4. (최적화) 한 번의 반복 동안 갱신이 전혀 없었다면,
        //    이미 최단 경로를 모두 찾은 것이므로 조기 종료
        if (!updated) {
            break;
        }
    }

    // 5. 음수 사이클 확인: V번째 반복 수행
    // V-1번 반복 후에도 거리가 계속 갱신된다면 음수 사이클이 존재
    for (const auto& edge : edges) {
        int from, to, weight;
        tie(from, to, weight) = edge;

        if (distances[from] != INF &&
            distances[to] > distances[from] + weight)
        {
            // 음수 사이클 발견
            return { true, {} };
        }
    }

    // 음수 사이클이 없으면 결과 반환
    return { false, distances };
}

int main() {
    // 테스트 1: 일반적인 경우 (음수 가중치 포함)
    int start = 0;
    int numNodes = 5;
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, -2},
        {1, 3, 5}, {2, 4, 6}, {3, 4, -3}
    };

    auto result1 = bellman_ford(start, numNodes, edges);
    if (result1.first) {
        cout << "테스트 1: 음수 사이클이 존재합니다." << endl;
    }
    else {
        cout << "테스트 1: 최단 경로" << endl;
        for (int i = 0; i < numNodes; ++i) {
            cout << start << " -> " << i << " : " << result1.second[i] << endl;
        }
    }

    cout << "\n---------------------------\n" << endl;

    // 테스트 2: 음수 사이클이 있는 경우
    vector<tuple<int, int, int>> edges_with_cycle = {
        {0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 1, -1}
    };

    auto result2 = bellman_ford(start, 4, edges_with_cycle);
    if (result2.first) {
        cout << "테스트 2: 음수 사이클이 존재합니다." << endl;
    }

    return 0;
}