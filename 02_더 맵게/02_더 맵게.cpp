#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 섞음 = 가장 낮은 값 + (두번째 낮은 값 * 2)
int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> MinHeap(scoville.begin(), scoville.end());
    
    while (true)
    {
        // 1. 스코빌 지수가 K보다 낮으면
        if (MinHeap.top() < K) 
        {
            // 더 이상 음식을 합칠 수 없으면 실패
            if (2 > MinHeap.size())
            {
                return -1;
            }

            int Min = MinHeap.top();
            MinHeap.pop();
            int NextMin = MinHeap.top();
            MinHeap.pop();

            // 2. 섞는다.
            int Combination = Min + (NextMin * 2);
            MinHeap.push(Combination);
            ++answer;
        }
        else // 3. 가장 낮은 스코빌 지수도 K보다 높다면
        {
            return answer;
        }
    }
}

int main()
{
    std::cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);
}

