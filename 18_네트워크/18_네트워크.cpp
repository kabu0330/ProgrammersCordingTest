
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(int start, vector<vector<int>> computers, vector<int>& visited)
{
    if (visited[start] == 1)
    {
        return;
    }

    visited[start] = true;

    for (int i = 0; i < computers[start].size(); i++)
    {
        if (start == i)
        {
            continue;
        }
        if (visited[i] == false && computers[start][i] == 1)
        {
            dfs(i, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    vector<int> visited(n, 0);
    int answer = 0;
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i] == false)
        {
            ++answer;
            dfs(i, computers, visited);
        }
    }
    return answer;
}

int main()
{
    int n1 = 3;
    vector<vector<int>> computers1 = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };

    int n2 = 3;
    vector<vector<int>> computers2 = { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} };

    int result1 = solution(n1, computers1);
    int result2 = solution(n2, computers2);
}