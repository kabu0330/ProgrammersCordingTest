
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> _vec)
{
    std::vector<int>::iterator newEnd = std::unique(_vec.begin(), _vec.end());
    std::sort(_vec.begin(), newEnd - 1, std::greater<>());
    std::vector<int> result(_vec.begin(), newEnd - 1);
    return result;
}

std::vector<int> solution2(std::vector<int> _vec)
{
    std::sort(_vec.begin(), _vec.end(), std::greater<>());
    _vec.erase(std::unique(_vec.begin(), _vec.end()), _vec.end());
    return _vec;
}

int main()
{
    std::vector<int> lst = { 4, 2, 2, 1, 3, 4 };
    std::vector<int> result = solution(lst);
    std::vector<int> result2 = solution2(lst);
    int a = 0;
}

