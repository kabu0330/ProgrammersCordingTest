#include <iostream>
#include <string>
#include <stack>

using namespace std;

//bool solution(string s)
//{
// /*   std::stack<char> Stack;
//    
//    for (size_t i = 0; i < s.size(); i++)
//    {
//        char Char = s[i];
//        if (Char == '(' || 
//            Char == '{' || 
//            Char == '['   )
//        {
//            Stack.push(Char);
//            continue;
//        }
//
//        if (true == Stack.empty())
//        {
//            return false;
//        }
//
//        if (Char == ')' && Stack.top() == '(' ||
//            Char == '}' && Stack.top() == '{' ||
//            Char == ']' && Stack.top() == '[')
//        {
//            Stack.pop();
//            continue;
//        }
//
//        return false;
//    }
//
//    if (true == Stack.empty())
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//    */
//}

bool solution(string s)
{

}

int main()
{
    std::string String = "(()(";
    bool Result = solution(String);
    int a = 0;
}
