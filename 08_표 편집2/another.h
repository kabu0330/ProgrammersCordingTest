#pragma once
#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

namespace another
{
    string solution(int n, int k, vector<string> cmd) 
    {
        vector<int> prev(n), next(n);
        for (int i = 0; i < n; i++)
        {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        stack<int> deletedStack;
        vector<int> exists(n, 1);
        int cur = k;

        for (const string& c : cmd)
        {
            char op = c[0];
            int x = 0;

            if (op == 'U' || op == 'D')
            {
                for (int i = 2; i < (int)c.size(); ++i) 
                {
                    x = x * 10 + (c[i] - '0');
                }

                if (op == 'U')
                {
                    while (x--)
                    {
                        cur = prev[cur];
                    }
                }
                else
                {
                    while (x--)
                    {
                        cur = next[cur];
                    }
                }
            }
            else if (op == 'C')
            {
                deletedStack.push(cur);
                exists[cur] = 0;

                int p = prev[cur];
                int ne = next[cur];
                if (p >= 0)
                {
                    next[p] = ne;
                }
                if (ne < n)
                {
                    prev[ne] = p;
                }
                cur = (ne < n ? ne : p);
            }
            else // 'Z' Undo: ������ ���� ����
            {
                int r = deletedStack.top();
                deletedStack.pop();
                exists[r] = 1;

                int p = prev[r];
                int n_ = next[r];
                if (p >= 0)
                {
                    next[p] = r;
                }
                if (n_ < n)
                {
                    prev[n_] = r;
                }        
            }
        }

        string answer;
        answer.reserve(n);  // reserve: ���� �뷮 �̸� Ȯ��
        for (int e : exists)
        {
            answer.push_back(e ? 'O' : 'X'); // push_back: ���ڿ� ���� ���� �߰�
        }
        return answer;
    }
}