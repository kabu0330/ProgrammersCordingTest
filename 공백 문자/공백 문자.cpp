#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string& _Str)
{
    std::vector<std::string> Result;
    std::string Test = _Str;
    int StartIndex = 0;
    int Index = 0;
    
    while (true)
    {
        Index = Test.find(' ', StartIndex);
        if (Index == StartIndex)
        {
            if (Index == Test.length() - 1)
            {
                break;
            }
            ++StartIndex;
            continue;
        }

        Result.push_back(Test.substr(StartIndex, Index - StartIndex));
        StartIndex = Index;
    }

    return Result;
}

int main()
{
    std::string Str = "I   love    you   ";
    solution(Str);
}

