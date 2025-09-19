
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct State
{
    int cost, x, y, dir;
    bool operator>(const State& state) const
    {
        return cost > state.cost;
    }
};

int solution(vector<vector<int>> board) 
{
    int n = board.size();

    vector<vector<vector<int>>> min_cost(n, vector<vector<int>>(n, vector<int>(4, numeric_limits<int>::max())));
    priority_queue<State, vector<State>, greater<State>> min_heap;
    
    for (int i = 0; i < 4; i++)
    {
        min_cost[0][0][i] = 0;
    }

    min_heap.push({ 0, 0, 0, -1 });

    while (!min_heap.empty())
    {
        State current = min_heap.top();
        min_heap.pop();

        if (current.dir != -1 && current.cost > min_cost[current.y][current.x][current.dir])
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[ny][nx] == 1)
            {
                continue;
            }

            int next_cost = current.cost + 100;
            if (current.dir != -1 && current.dir != i)
            {
                next_cost += 500;
            }
            
            if (next_cost < min_cost[ny][nx][i])
            {
                min_cost[ny][nx][i] = next_cost;
                min_heap.push({ next_cost, nx, ny, i });
            }
        }
    }

    int answer = numeric_limits<int>::max();
    for (int i = 0; i < 4; i++)
    {
        if (min_cost[n - 1][n - 1][i] < answer)
        {
            answer = min_cost[n - 1][n - 1][i];
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board0 = {
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}};
    vector<vector<int>> board1 = {
        {0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0, 1}, 
        {0, 0, 1, 0, 0, 0, 1, 0}, 
        {0, 1, 0, 0, 0, 1, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0}};

    int result0 = solution(board0);
    int result1 = solution(board1);
}
