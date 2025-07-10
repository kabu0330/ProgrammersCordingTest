

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int bfs(const vector<vector<int>>& maps)
{
    int row = maps.size();
    int col = maps[0].size();

    int startX = 0;
    int startY = 0;
    int destX = col - 1;
    int destY = row -1;

    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { -1, 0, 1, 0 };
    
    queue<tuple<int, int, int>> queue;
    vector<vector<int>> visited(row, vector<int>(col, 0));
    
    queue.emplace(startY, startX, 1);
    visited[startY][startX] = 1;

    while (false == queue.empty())
    {
        auto [curY, curX, dist] = queue.front();
        queue.pop();

        if (curX == destX && curY == destY)
        {
            return dist;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX >= 0 && nextX < col && nextY >= 0 && nextY < row)
            {
                if (maps[nextY][nextX] == 1)
                {
                    if (visited[nextY][nextX] == 0)
                    {
                        queue.emplace(nextY, nextX, dist + 1);
                        visited[nextY][nextX] = 1;
                    }
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int result = bfs(maps);
    return result;
}

int main()
{
    vector<vector<int>> maps1 = 
    {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 0, 1}, 
        {0, 0, 0, 0, 1}};
    vector<vector<int>> maps2 = 
    {
        {1, 0, 1, 1, 1}, 
        {1, 0, 1, 0, 1}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 1}};

    int result1 = solution(maps1);
    int result2 = solution(maps2);
}
