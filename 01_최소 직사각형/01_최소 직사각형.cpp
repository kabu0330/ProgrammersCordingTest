#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    for (size_t i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            std::swap(sizes[i][0], sizes[i][1]);
        }
    }

    int LeftMax = 0;
    for (size_t i = 0; i < sizes.size(); i++)
    {
        if (LeftMax < sizes[i][0])
        {
            LeftMax = sizes[i][0];
        }
    }

    int RightMax = 0;
    for (size_t i = 0; i < sizes.size(); i++)
    {
        if (RightMax < sizes[i][1])
        {
            RightMax = sizes[i][1];
        }
    }

    return LeftMax * RightMax;
}

int main()
{
    std::cout << solution({{ 60, 50 }, { 30, 70 }, { 60, 30 }, { 80, 40 }});
}

