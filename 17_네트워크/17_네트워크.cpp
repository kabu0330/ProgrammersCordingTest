

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, int num, const vector<vector<int>>& computers, vector<int>& visited)
{
    queue<int> queue;
    queue.push(start);

    while (false == queue.empty())
    {
        int idx = queue.front();
        queue.pop();

        for (int i = 0; i < num; i++)
        {
            if (i == idx)
            {
                continue;
            }
            if (computers[idx][i] == 1)
            {
                if (visited[i] == false)
                {
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    vector<int> visited(n, 0);
    int network = 0;

    for (int i = 0; i < computers.size(); i++)
    {
        if (false == visited[i])
        {
            ++network;
            bfs(i, n, computers, visited);
        }
    }

    return network;
}

int main()
{
    int n1 = 3;
    vector<vector<int>> computers1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    
    int n2 = 3;
    vector<vector<int>> computers2 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

    int result1 = solution(n1, computers1);
    int result2 = solution(n2, computers2);
}

