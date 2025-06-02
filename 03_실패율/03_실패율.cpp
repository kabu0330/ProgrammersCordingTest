
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "another.h"

using namespace std;

bool Compare(pair<int, float>& _Left, pair<int, float>& _Right)
{
    if (_Left.second == _Right.second)
    {
        return _Left.first < _Right.first;
    }
    return _Left.second > _Right.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    
    // 1. 각 스테이지에 도달한 수를 구하기
    // 2. 각 스테이지별 실패율 구하기
    // 3. 실패율을 기준으로 내림차순
    // 4. 동률이면 낮은 번호 순

    // vector<int> 도달했으나 클리어하지 못한 플레이어 수
    // vector<int> 클리어한 수
    // 실패율 = 도달만 한 수 / 클리어한 수
    
    vector<float> Challengers(N + 2, 0.0f);
    vector<float> StageCompleters(N + 2, 0.0f);
    
    // 도달
    for (int i = 0; i < stages.size(); i++)
    {
        int a = stages[i];
        for (int j = 1; j <= stages[i]; j++)
        {
            StageCompleters[j]++;
        }
        Challengers[stages[i]]++;
    }
    
    vector<pair<int, float>> FailureRates(N);
    for (int i = 0; i < N; i++)
    {
        FailureRates[i].first = i + 1;
        if (0 == Challengers[i + 1])
        {
            FailureRates[i].second = 0;
        }
        else
        {
            float FailureRate = Challengers[i + 1] / StageCompleters[i + 1];
            FailureRates[i].second = FailureRate;
        }
    }
    
    std::sort(FailureRates.begin(), FailureRates.end(), Compare);
    for (size_t i = 0; i < FailureRates.size(); i++)
    {
        answer[i] = FailureRates[i].first;
    }
    return answer;
}

int main()
{
    int N = 5;
    vector<int> Stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    vector<int> Result = solution(N, Stages);
    another_solution(N, Stages);
}
