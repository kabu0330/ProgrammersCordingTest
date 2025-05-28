
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

std::vector<int> solution(std::vector<int>& _vec)
{
    std::sort(_vec.begin(), _vec.end());
    return _vec;
}

void bubbleSort(std::vector<int>& _vec)
{
    for (size_t i = 0; i < _vec.size() - 1; i++)
    {
        for (size_t j = 0; j < _vec.size() - i - 1; j++)
        {
            if (_vec[j] > _vec[j + 1] )
            {
                std::swap(_vec[j], _vec[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> vec = { 1, -5, 2, 4, 3 };
    std::vector<int> result = solution(vec);

    std::vector<int> vec2(100000);
    for (int i = 0; i < vec2.size(); i++)
    {
        vec2[i] = i + 1;
    }

    std::vector<int> vecForBubbleSort = vec2;
    clock_t startBubbleSort = ::clock();
    bubbleSort(vecForBubbleSort);
    clock_t endBubbleSort = ::clock();
    double timeBubbleSort = double(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;

    std::vector<int> vecForStdSort = vec2;
    clock_t startStdSort = ::clock();
    std::sort(vecForStdSort.begin(), vecForStdSort.end());
    clock_t endStdSort = ::clock();
    double timeStdSort = double(endStdSort - startStdSort) / CLOCKS_PER_SEC;
}

