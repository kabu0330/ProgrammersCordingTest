#include <iostream>

#include <string>
#include <vector>

#include "Another.h"

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int Rows = static_cast<int>(triangle.size());
    int Cols = static_cast<int>(triangle[Rows - 1].size());

    std::vector<std::vector<int>> Matrix(Rows, std::vector<int>(Cols, 0));
    // 1. 첫줄은 [0][0]만 값이 존재하고 나머지 열은 0이다.
    // 2. x가 0이면 [y - 1][x] 값만 더할 수 있다.
    // 3. y == x면 [y - 1][x - 1] 값만 더할 수 있다.
    // 4. y가 2면서 2, 3번이 아니라면 [y - 1][x] 와 [y - 1][x - 1] 중 큰 값만 더할 수 있다.
    
    for (int y = 0; y < Rows; y++)
    {
        for (int x = 0; x < Cols; x++)
        {
            if (0 == x && 0 == y)
            {
                Matrix[y][x] = triangle[y][x];
            }
            else if (0 == y || y < x)
            {
                continue;
            }
            else if (0 == x)
            {
                Matrix[y][x] = triangle[y][x] + Matrix[y - 1][x];
            }
            else if (y == x)
            {
                Matrix[y][x] = triangle[y][x] + Matrix[y - 1][x - 1];
            }
            else
            {
                Matrix[y][x] = triangle[y][x] + std::max(Matrix[y - 1][x], Matrix[y - 1][x - 1]);
            }
        }
    }

    int Result = -1;
    for (int i = 0; i < Cols; i++)
    {
        Result = std::max(Matrix[Rows - 1][i], Result);
    }
    return Result;
}

int main()
{
    std::vector<std::vector<int>> Triangle =
    {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5},
        //{1, 1, 9, 0, 0, 0}
    };

    std::cout << solution(Triangle) << std::endl;
    std::cout << solution1(Triangle);
}
