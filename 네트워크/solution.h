#pragma once
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    std::vector<bool> Visited(n, false);
    
    for (int i = 0; i < n; i++) // ��� ��Ʈ��ũ�� ��ȸ�Ѵ�.
    {
        if (true == Visited[i]) // ���� ���θ� Ȯ������ ���� ��Ʈ��ũ�� �����Ѵ�.
        {
            continue;
        }
        std::queue<int> Queue; 
        Queue.push(i);
        while (true != Queue.empty()) 
        {
            int Value = Queue.front();
            Queue.pop();
            
            if (true == Visited[Value]) // ������ �湮�� ���� �ִ���?
            {
                continue;
            }

            Visited[Value] = true; // ó�� �湮�ϸ� true�� �ٲٰ�

            for (int j = 0; j < n; j++) 
            {
                if (computers[Value][j] == 1) // ���� ����� �༮��
                {
                    if (false == Visited[j]) // �湮�� ���� ���� �༮��
                    {
                        if (Value != j) // �� �ڽ��� �ƴ� �༮�̸�
                        {
                            Queue.push(j); // �湮�� ���� ���� �ٸ� ��Ʈ��ũ��.
                        }
                    }
                }
            }
        }
        // ���� ����� ��Ʈ��ũ�� �� ���� �� ���Ҵ�.
        ++answer;
    }

    return answer;
}