
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> number1 = { 1, 2, 3, 4, 5 };
std::vector<int> number2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
std::vector<int> number3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

std::vector<int> solution(std::vector<int> answers)
{
    vector<int> answer;
    vector<int> count(3, 0);
    
    for (size_t i = 0; i < answers.size(); i++)
    {
        if (answers[i] == number1[i % number1.size()])
        {
            count[0]++;
        }
        if (answers[i] == number2[i % number2.size()])
        {
            count[1]++;
        }
        if (answers[i] == number3[i % number3.size()])
        {
            count[2]++;
        }
    }

    int maxValue = *max_element(count.begin(), count.end());

    for (size_t i = 0; i < count.size(); i++)
    {
        if (maxValue == count[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}


int main()
{
    std::vector<int> answers = { 1, 2, 3, 4, 5 };
    std::vector<int> result = solution(answers);
}
