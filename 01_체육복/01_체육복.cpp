#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    std::sort(lost.begin(), lost.end());
    std::sort(reserve.begin(), reserve.end());

    for (size_t i = 0; i < lost.size(); i++)
    {
        for (size_t j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    for (size_t i = 0; i < lost.size(); i++)
    {
        if (-1 == lost[i])
        {
            continue;
        }

        for (size_t j = 0; j < reserve.size(); j++)
        {
            if (-1 == reserve[j])
            {
                continue;
            }

            if (1 == std::abs(lost[i] - reserve[j]))
            {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }

    int Result = n;
    for (size_t i = 0; i < lost.size(); i++)
    {
        if (-1 != lost[i])
        {
            --Result;
        }
    }
    return Result;
}

int main()
{
    std::cout << solution(5, { 2, 3, 4 }, { 3 });
}
