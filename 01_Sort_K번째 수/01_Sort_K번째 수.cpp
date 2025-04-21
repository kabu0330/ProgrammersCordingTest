#include <iostream>
#include <vector>

//#include "Solution.h"
#include "AnotherApproach.h"

int main()
{
    std::vector<int> Array = { 1, 5, 2, 6, 3, 7, 4 };
    std::vector<std::vector<int>> Commands;
    Commands.push_back({ 2, 5, 3 });
    Commands.push_back({ 4, 4, 1 });
    Commands.push_back({ 1, 7, 3 });
   
    std::vector<int> Result = solution(Array, Commands);
    for (size_t i = 0; i < Result.size(); i++)
    {
        cout << Result[i] << ",";
    }
}
