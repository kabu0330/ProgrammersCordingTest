#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// location 몇번(0~) 째로 나오냐 
// return 벡터의 원래 순번 1~
int solution(vector<int> priorities, int location) 
{
    int answer = 0;

    std::priority_queue<int> PriorityQueue;
    std::queue<pair<int, int>> Queue;
    for (size_t i = 0; i < priorities.size(); i++)
    {
        PriorityQueue.push(priorities[i]);
        Queue.push({ i, priorities[i] });
    }



    return answer;
}

int main()
{
    std::vector<int> Priorities{ 2, 1, 3, 2 };
    int Result = solution(Priorities, 2);

}
