#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    std::vector<bool> Visited(n, false);
    
    for (int i = 0; i < n; i++) // 모든 네트워크를 순회한다.
    {
        if (true == Visited[i]) // 연결 여부를 확인하지 않은 네트워크만 조사한다.
        {
            continue;
        }
        std::queue<int> Queue; 
        Queue.push(i);
        while (true != Queue.empty()) 
        {
            int Value = Queue.front();
            Queue.pop();
            
            if (true == Visited[Value]) // 이전에 방문한 적이 있는지?
            {
                continue;
            }

            Visited[Value] = true; // 처음 방문하면 true로 바꾸고

            for (int j = 0; j < n; j++) 
            {
                if (computers[Value][j] == 1) // 나와 연결된 녀석만
                {
                    if (false == Visited[j]) // 방문한 적이 없는 녀석만
                    {
                        if (Value != j) // 나 자신이 아닌 녀석이면
                        {
                            Queue.push(j); // 방문한 적이 없는 다른 네트워크다.
                        }
                    }
                }
            }
        }
        // 나와 연결된 네트워크를 한 바퀴 다 돌았다.
        ++answer;
    }

    return answer;
}