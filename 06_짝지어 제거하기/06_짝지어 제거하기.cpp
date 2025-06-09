
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    std::stack<char> stk;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (true == stk.empty())
        {
            stk.push(s[i]);
            continue;
        }

        char ch = stk.top();
        char curCh = s[i];
        if (curCh == ch)
        {
            stk.pop();
        }
        else
        {
            stk.push(curCh);
        }
    }
    
    return static_cast<int>(true == stk.empty());
}

int main()
{
    std::string str = "cdcd";
    int Result = solution(str);
}
