#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// location 몇 번(first Index : 0 ~) 째로 나오냐 
// return 벡터의 원래 순번(first Index : 1 ~)
int solution(vector<int> priorities, int location) 
{
    int answer = 0;

    std::priority_queue<int> PriorityQueue; // 내림차순 정렬
    std::queue<pair<int, int>> Queue; 
    for (size_t i = 0; i < priorities.size(); i++)
    {
        PriorityQueue.push(priorities[i]); 
        Queue.push({ i, priorities[i] }); // Index, 우선순위
    }
    // PriorityQueue : 3, 2, 2, 1
    // Queue : (0, 2), (1, 1), (2, 3), (3, 2)
    
    // Debug Code
    //int Result0 = PriorityQueue.top();
    //int Result1 = Queue.front().second;
    //

    while (false == Queue.empty())
    {
        // 우선순위가 가장 높은 값이면
        if (PriorityQueue.top() == Queue.front().second)
        {
            answer++;
            if (location == Queue.front().first) // location과 일치하는 인덱스면 리턴
            {
                return answer;
            }
            // 일치하지 않으면 제거
            PriorityQueue.pop();
            Queue.pop();
        }
        else // 우선순위가 가장 높은 값이 아니라면
        {
            // 다시 맨 끝으로 집어넣는다.
            Queue.push({ Queue.front().first, Queue.front().second });
            Queue.pop();
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Priorities{ 1, 1, 9, 1, 1, 1 };
    int Result = solution(Priorities, 0);

}
