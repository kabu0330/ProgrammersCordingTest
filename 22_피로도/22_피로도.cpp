#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_dungeon = 0;

void backtrack(int current_k, int count, vector<bool>& visited, const vector<vector<int>>& dungeons)
{
    max_dungeon = ::max(max_dungeon, count);

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && current_k >= dungeons[i][0])
        {
            visited[i] = true;
            backtrack(current_k - dungeons[i][1], count + 1, visited, dungeons);
            visited[i] = false;
            
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    backtrack(k, 0, visited, dungeons);
    return max_dungeon;
}

int main()
{
    // 피로도
    int k = 80; 

    // 입장 컷 피로도, 소모 피로도
    vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };
    int result = solution(k, dungeons);
}

