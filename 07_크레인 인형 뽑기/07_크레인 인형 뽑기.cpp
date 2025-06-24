
#include <iostream>
#include "another.h"

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> boards(board[0].size());

    for (int y = board.size() - 1; y >= 0; --y)
    {
        for (int x = 0; x < board[0].size(); x++)
        {
            if (board[y][x])
            {
                boards[x].push(board[y][x]);

            }
        }
    }

    stack<int> stk;
    for (int element : moves)
    {
        int index = element - 1;
        if (true == boards[index].empty())
        {
            continue;
        }
        else
        {
            int value = boards[index].top();
            boards[index].pop();
            
            if (false == stk.empty() && value == stk.top())
            {
                stk.pop();
                answer += 2;
                continue;
            }
            else
            {
                stk.push(value);
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}
    };

    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    int result = solution(board, moves);
    int result2 = solution2(board, moves);

    int a = 0;
}

