
#include <iostream>
#include "another.h"


#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;


string solution(int n, int k, vector<string> cmd) {

    std::list<int> table;
    for (int i = 0; i < n; i++)
    {
        table.push_back(i);
    }

    auto curIt = table.begin();
    std::advance(curIt, k);

    stack<int> deletedStack;
    string result(n, 'X');

    for (const string& command : cmd)
    {
        char op = command[0];
        int x = 0;

        if (op == 'U' || op == 'D')
        {
            for (int i = 2; i < (int)command.size(); i++)
            {
                x = x * 10 + (command[i] - '0');
            }

            if (op == 'U')
            {
                while (x--)
                {
                    --curIt;
                }
            }
            else
            {
                while (x--)
                {
                    ++curIt;
                }
            }
        }
        else if (op == 'C')
        {
            deletedStack.push(*curIt);
            curIt = table.erase(curIt);
            if (curIt == table.end())
            {
                --curIt;
            }
        }
        else if (op == 'Z')
        {
            int r = deletedStack.top();
            deletedStack.pop();

            auto it = table.begin();
            while (it != table.end() && *it < r)
            {
                ++it;
            }
            
            table.insert(it, r);
        }
        
    }

    for (int idx : table)
    {
        result[idx] = 'O';
    }

    return result;
}

int main()
{
    int n = 8;
    int k = 2;
    vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
    string result = solution(n, k, cmd);
    string result2 = another::solution(n, k, cmd);

    int a = 0;
}
