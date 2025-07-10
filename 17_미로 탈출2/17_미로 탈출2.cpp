
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

// 인덱스 범위 벗어나지 않게 설정
bool isWithin(int x, int y, int maxX, int maxY)
{
    return y >= 0 && y <= maxY && x >= 0 && x <= maxX;
}

bool isWall(int x, int y, const vector<string>& maps)
{
    if (x < 0 || y < 0)
    {
        return true;
    }
    return maps[y][x] == 'X';
}

// 1. 시작지점부터 레버까지
// 2. 레버부터 출구까지 
// 두 번에 나눠서 시간을 계산한다.
int bfs(int startX, int startY, int endX, int endY, const vector<string>& maps)
{
    //           y,   x
    queue<tuple<int, int, int>> queue;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));

    // 매번 네 방향으로 갈 수 있는지 반복 탐색할 것이므로 순서 상관없다.
    int dx[4] = {  0, -1, 0, 1 };
    int dy[4] = { -1,  0, 1, 0 };

    queue.emplace(startY, startX, 0);
    visited[startY][startX] = 1; // 방문한 곳으로 되돌아가지 마
    int totalTime = 0;

    while (false == queue.empty())
    {
        auto [curY, curX, time] = queue.front();
        queue.pop();

        if (curX == endX && curY == endY) // 탈출 조건
        {
            return totalTime;
        }

        for (int i = 0; i < 4; i++)
        {
            int posX = curX + dx[i];
            int posY = curY + dy[i];
         
            if (false == isWithin(posX, posY, endX, endY) && // 범위 밖이거나
                true == isWall(posX, posY, maps)) // 벽이면, 갈 수 없다.
            {
                continue;
            }
            if (isWithin(posX, posY, endX, endY) && 
                true == visited[posY][posX]) // 이미 방문한 길로 가지 않는다.
            {
                continue;
            }

            queue.emplace(posY, posX, ++time); // 한 걸음 나아간다.
            visited[posY][posX] = 1;
        }
    } 
    return -1;
}

// S, L, E 위치 인덱스 추출
vector<int> findPos(char findChar, const vector<string>& maps)
{
    vector<int> pos(2, -1);
    int row = maps.size();
    int col = maps[0].size();
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            if (findChar == maps[y][x])
            {
                pos[0] = x;
                pos[1] = y;
                return pos;
            }
        }
    }
    return pos;
}

int solution(vector<string> maps)
{
    vector<int> startPos = findPos('S', maps);
    vector<int> LeverPos = findPos('L', maps);
    vector<int> ExitPos = findPos('E', maps);

    // 1. 시작 지점부터 레버 위치까지
    int distanceToLever = bfs(startPos[0], startPos[1], LeverPos[0], LeverPos[1], maps);
    if (distanceToLever == -1)
    {
        return -1;
    }

    // 2. 레버 위치부터 탈출 위치까지
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
