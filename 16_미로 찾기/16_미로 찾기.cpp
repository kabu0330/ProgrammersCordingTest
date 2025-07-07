
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int x, y, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;
bool isWithinRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

Point findStartPoint(char start, vector<string>& maps)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == start)
            {
                return { i, j, 0 };
            }
        }
    }
    return { -1, -1, -1 };
}

int bfs(char start, char end, vector<string>& maps)
{
    bool visited[101][101] = { false };
    queue<Point> queue;

    queue.push(findStartPoint(start, maps));

    while (!queue.empty())
    {
        Point current = queue.front();
        queue.pop();

        if (maps[current.y][current.x] == end)
        {
            return current.cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];

            if (isWithinRange(ny, nx) && !visited[ny][nx] && maps[ny][nx] != 'X')
            {
                queue.emplace(ny, nx, current.cnt + 1);
                visited[ny][nx] = true;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) 
{
    n = maps.size();
    m = maps[0].size();

    int distanceToL = bfs('S', 'L', maps);
    if (distanceToL == -1)
    {
        return -1;
    }

    int distanceToE = bfs('L', 'E', maps);
    return distanceToE == -1 ? -1 : distanceToL + distanceToE;
}

int main()
{
    vector<string> maps = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    vector<string> maps2 = { "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" };
    int result1 = solution(maps);
    int result2 = solution(maps2);
}

