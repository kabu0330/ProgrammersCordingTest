
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Compare(pair<int, double>& _Left, pair<int, double>& _Right)
{
    if (_Left.second == _Right.second)
    {
        return _Left.first < _Right.first;
    }
    return _Left.second > _Right.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 1. 각 스테이지에 도달한 수를 구하기
    // 2. 각 스테이지별 실패율 구하기
    // 3. 실패율을 기준으로 내림차순
    // 4. 동률이면 낮은 번호 순

    // unordered_map<스테이지, 도달한 수>
    // 실패율 =  현재 스테이지 도달한 수 / 상위 스테이지 도달한 수
    // unordered_map<스테이지, 실패율>
    // std::sort : 실패율이 높은 애 먼저, 만약 같으면 스테이지가 빠른 애 먼저
    
    vector<float> Challenger(N + 2, 0.0f);
    vector<float> Fail(N + 2, 0.0f);

    for (int i = 0; i < stages.size(); i++)
    {
        int CurStage = stages[i];
        for (int j = 1; j <= CurStage; j++)
        {
            Challenger[j]++;
        }
        Fail[CurStage]++;
    }

    

    return answer;
}

int main()
{
    int N = 5;
    vector<int> Stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    vector<int> Result = solution(N, Stages);
}
