#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    int Size = prices.size();
    vector<int> answer(Size); // 가격이 하락하지 않은 시간
    std::stack<int> Stack; // 이전과 다음을 비교하기에 최적화된 자료구조

    for (size_t i = 0; i < prices.size(); i++)
    {
        // 2. 현재 값보다 가격이 하락한 시점은 모두 시간 저장
        while (false == Stack.empty() && prices[i] < prices[Stack.top()])
        {
            int TopIndex = Stack.top(); 
            Stack.pop();

            answer[TopIndex] = i - TopIndex;
        }

        // 1. 처음이거나 가격이 하락하지 않았다면 인덱스 저장
        Stack.push(i);
    }

    // 3. 가격이 하락하지 않은 모든 인덱스들의 시간 계산
    while (false == Stack.empty())
    {
        int TopIndex = Stack.top();
        Stack.pop();
        answer[TopIndex] = Size - TopIndex - 1;
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution({ 5, 6, 3, 2, 1 });
    for (size_t i = 0; i < Result.size(); i++)
    {
        std::cout << Result[i] << ", ";
    }
}
