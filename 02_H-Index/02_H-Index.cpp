#include <iostream>
#include "solution.h"

int main()
{
    //std::vector<int> citations = { 3, 0, 6, 1, 5 };
    std::vector<int> citations /*= { 100, 200, 300}*/;

    for (int i = 100; i > 0; --i)
    {
        citations.push_back(i);
    }
    int Result = solution(citations);

    std::cout << Result << std::endl;
}
