
#include <iostream>
#include <vector>

using namespace std;
/* 1. 승자가 k점을 가져간다. k는 최대 10점
*  2. 더 많은 화살을 k점에 맞힌 선수가 승리
*  3. 동점이면 어피치가 가져간다.
*  4. 어피치가 먼저 쏘고 라이언이 쏜다.
*/
vector<int> vec(11, 0);
int max_score = -1;

void solve(int remain, int cur_score, const vector<int>& info)
{
    if (0 >= remain)
    {
        cout << "남은 화살 없음" << endl;
        return;
    }
    
    for (int i = 0; i < info.size(); i++)
    {
        int value = info[i];
        if (remain < value)
        {
            return;
        }
        int score = 10 - i;
        int arrow = remain - value;
        solve(arrow, score + cur_score, info);
    }
    
}

vector<int> solution(int n, const vector<int>& info)
{
    
    solve(n, 0, info);

    return vec;
}

int main()
{
    int n = 5;
    vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
    vector<int> result = solution(n, info);
}

