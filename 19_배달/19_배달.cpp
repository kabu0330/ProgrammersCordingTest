#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
using namespace std;

//              거리, 노드
using PII = pair<int, int>;
int MAX = numeric_limits<int>::max();

int solution(int N, vector<vector<int>> road, int K) {
    // 마을1, {거리, 마을2}
    vector<vector<PII>> adj(N + 1);
    for (const auto& r : road)
    {
        adj[r[0]].push_back({ r[2], r[1] });
        adj[r[1]].push_back({ r[2], r[0] });
    } // 양방향 마을 연결 상태 저장

    priority_queue<PII, vector<PII>, greater<PII>> min_heap;
    vector<int> min_time(N + 1, MAX);

    min_time[1] = 0;
    min_heap.push({ 0, 1 });

    while (!min_heap.empty())
    {
        int cur_time = min_heap.top().first;
        int cur_node = min_heap.top().second;
        min_heap.pop();

        if (cur_time > min_time[cur_node])
        {
            continue;
        }

        for (int i = 0; i < adj[cur_node].size(); i++)
        {
            int next_time = adj[cur_node][i].first;
            int next_node = adj[cur_node][i].second;

            int total_time = next_time + cur_time;
            if (total_time < min_time[next_node])
            {
                min_time[next_node] = total_time;
                min_heap.push({ total_time, next_node });
            }
        }
    }

    int answer = 0;
    for (int time : min_time)
    {
        if (time <= K)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    int n = 5;
    int k = 3;
    vector<vector<int>> road = {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}};
    int result = solution(n, road, k);
}

