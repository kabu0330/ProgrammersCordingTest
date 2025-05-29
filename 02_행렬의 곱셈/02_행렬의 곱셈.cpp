
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer(arr1.size(), std::vector<int>(arr2[0].size(), 0));

    for (size_t y = 0; y < arr1.size(); y++)
    {
        for (size_t x = 0; x < arr2[0].size(); x++)
        {
            for (size_t a = 0; a < arr2.size(); a++)
            {
                answer[y][x] += arr1[y][a] * arr2[a][x];
            }
        }
    }

    return answer;
}

int main()
{
    std::vector<std::vector<int>> arr1 = { {1, 4}, {3, 2 }, {4, 1} };
    std::vector<std::vector<int>> arr2 = { {3, 3}, {3, 3 } };
    std::vector<std::vector<int>> Result = solution(arr1, arr2);
}
