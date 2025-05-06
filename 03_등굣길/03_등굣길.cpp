#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    std::vector<std::vector<int>> DP(n + 1, std::vector<int>(m + 1, 0));

    // 물웅덩이
    for (const std::vector<int>& Puddle : puddles)
    {
        int x = Puddle[0];
        int y = Puddle[1];
        DP[y][x] = -1;
    }

    DP[1][1] = 1;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (DP[y][x] == -1)
            {
                DP[y][x] = 0;
                continue;
            }

            if (DP[y - 1][x] > 0)
            {
                DP[y][x] += DP[y - 1][x];
            }
            if (DP[y][x -1] > 0)
            {
                DP[y][x] += DP[y][x - 1];
            }
            DP[y][x] %= 1000000007;
        }
    }
    
    return  DP[n][m];
}

int main()
{
    std::cout << solution(4, 3, { { 2, 2 } });
}
