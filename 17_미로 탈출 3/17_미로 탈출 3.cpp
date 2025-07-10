
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int bfs(int startX, int startY, int endX, int endY, const vector<string>& maps)
{
    int row = maps.size();
    int col = maps[0].size();

    // 순서는 중요하지 않다. 
    // 결국 네 번 다 이동해볼 것이기 때문
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { -1, 0, 1, 0 };

    //           y,   x,  time
	queue<tuple<int, int, int>> queue;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));

    queue.emplace(startY, startX, 0);
    visited[startY][startX] = 1;

    while (false == queue.empty())
    {
        int curX = get<1>(queue.front());
        int curY = get<0>(queue.front());
        int time = get<2>(queue.front());
        queue.pop();

        if (curX == endX && curY == endY)
        {
            return time;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX >= 0 && nextX < col && nextY >= 0 && nextY < row)
            {
                if (maps[nextY][nextX] != 'X')
                {
                    if (visited[nextY][nextX] == 0)
                    {
                        queue.emplace(nextY, nextX, time + 1);
                        visited[nextY][nextX] = 1;
                    }
                }
            }
        }
    }

    return -1;
}

vector<int> findIndex(char findChar, const vector<string>& maps)
{
    int row = maps.size();
    int col = maps[0].size();

    vector<int> index(2, -1);

    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            if (maps[y][x] == findChar)
            {
                index[0] = x;
                index[1] = y;
                return index;
            }
        }
    }

    return index;
}

int solution(vector<string> maps)
{
    vector<int> startPos = findIndex('S', maps);
    vector<int> LeverPos = findIndex('L', maps);
    vector<int> ExitPos = findIndex('E', maps);

    int distanceToLever = bfs(startPos[0], startPos[1], LeverPos[0], LeverPos[1], maps);
    if (distanceToLever == -1)
    {
        return -1;
    }

    int distanceToExit = bfs(LeverPos[0], LeverPos[1], ExitPos[0], ExitPos[1], maps);
    if (distanceToExit == -1)
    {
        return -1;
    }

    return distanceToLever + distanceToExit;
}

int main()
{
    vector<string> maps = { "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" };
    vector<string> maps2 = { "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" };
    int result1 = solution(maps);
    int result2 = solution(maps2);
}

