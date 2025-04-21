#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const std::string& _Left, const std::string& _Right)
{
    std::string Left = _Left + _Right;
    std::string Right = _Right +_Left;
    return Left > Right; // 해당 열의 문자의 ASCII가 더 큰 쪽
}

string solution(vector<int> numbers) 
{
    string answer = "";    
    std::vector<string> VectorString;
    for (int Num : numbers)
    {
        VectorString.push_back(std::to_string(Num)); 
    }
    std::sort(VectorString.begin(), VectorString.end(), Compare);

    if (VectorString[0] == "0")
    {
        return "0";
    }

    for (string& Str : VectorString)
    {
        answer += Str;
    }

    return answer;
}

