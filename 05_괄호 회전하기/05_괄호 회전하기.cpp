#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

std::unordered_map<char, char> bracketPair = 
{ // 닫힘, 열림   Pair
    {')', '('}, 
    {'}', '{'}, 
    {'[', ']'} 
};

bool isValid(std::string& str, int start)
{
    std::stack<char> stack;
    unsigned int size = str.size();
    
    for (int i = 0; i < size; i++)
    {
        int index = (start + i) % size; // 괄호가 이동하는게 아니라 탐색 순서만 한 칸씩 이동하고 맨 끝이면 다시 0번 인덱스로 돌아간다.
        char ch = str[index];

        int a = bracketPair.count(ch);

        if (1 == bracketPair.count(ch))
        {
            if (stack.empty() || stack.top() != bracketPair[ch])
            {
                return false;
            }
            
            stack.pop();
        }
        else
        {
            stack.push(ch);
        }
    }

    return stack.empty();
}

int solution(std::string str)
{
    int answer = 0;
    for (int i = 0; i < str.size(); i++)
    {
        answer += isValid(str, i);
    }

    return answer;
}

int main()
{
    std::string str = "[](){}";
    int result = solution(str);
}
