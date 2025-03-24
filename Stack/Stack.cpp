#include <iostream>
#include <stack>

std::string Reverse(const std::string& _Str)
{
    std::stack<char> Stack;
    for (char Char : _Str)
    {
        Stack.push(Char);
    }

    std::string Res = "";
    while (false == Stack.empty())
    {
        Res += Stack.top();
        Stack.pop();
    }

    return Res;
}


int main()
{
    std::string Str1 = "HELLO";
    std::string Str2 = "ALGORITHM";

    std::cout << Str1 << " -> " << Reverse(Str1) << std::endl;
    std::cout << Str2 << " -> " << Reverse(Str2) << std::endl;
}

