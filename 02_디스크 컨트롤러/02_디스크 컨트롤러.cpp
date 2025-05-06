#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// jobs {요청 시간, 처리 시간}
// 우선순위 1. 처리 시간, 2. 요청 시간, 3. 순서
// pair<요청 시간, 처리 시간>
int solution(vector<vector<int>> jobs) 
{
    std::sort(jobs.begin(), jobs.end()); // 요청 시간 순 정렬 {요청 시간, 처리 시간}
 
    // 처리 시간 순 정렬 {처리 시간, 요청 시간}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> MinHeap;

    int CurTime = 0;
    int JobIndex = 0;
    int TotalJobSize = jobs.size();
    int TotalTime = 0; // 작업 시간(현재 시간 - 요청 시간)의 합

    while (true)
    {
        if (JobIndex == TotalJobSize && true == MinHeap.empty())
        {
            break;
        }
        
        // 현재 시간까지 요청이 들어온 모든 작업을 추가
        while (JobIndex < TotalJobSize && jobs[JobIndex][0] <= CurTime)
        {
            //                 처리 시간,           요청 시간
            MinHeap.push({ jobs[JobIndex][1], jobs[JobIndex][0] });
            ++JobIndex;
        }

        // 현재 시각 작업 요청이 있다면, 작업 하나만 수행.
        // 작업이 끝난 시간에 들어온 요청이 우선순위가 높을 수도 있기 때문에 하나만 수행
        if (false == MinHeap.empty())
        {
            int Duration = MinHeap.top().first;
            int RequestTime = MinHeap.top().second;
            MinHeap.pop();
            CurTime += Duration;
            TotalTime += CurTime - RequestTime;
            continue;
        }
        else // 현재 시간까지 들어온 요청이 없다면
        {
            CurTime = jobs[JobIndex][0]; // 다음 작업 요청이 존재하는 시간까지 이동
        }
    }

    return TotalTime / TotalJobSize;
}

int main()
{
    std::cout << solution({ { 0, 3 }, { 1, 9 }, { 3, 5 } });
}

