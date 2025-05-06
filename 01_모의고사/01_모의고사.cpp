#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    std::vector<std::vector<int>> Students = {
        { 1, 2, 3, 4, 5 },
        { 2, 1, 2, 3, 2, 4, 2, 5 },
        { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }
    };

    std::vector<int> Scores(3, 0);
    for (size_t i = 0; i < answers.size(); i++)
    {
        for (size_t j = 0; j < Students.size(); j++)
        {
            int QuestNumber = i % Students[j].size();
            if (answers[i] == Students[j][QuestNumber])
            {
                ++Scores[j];
            }
        }
    }
    
    int MaxScore = *std::max_element(Scores.begin(), Scores.end());
    
    std::vector<int> Result;
    for (size_t i = 0; i < Scores.size(); i++)
    {
        if (MaxScore == Scores[i])
        {
            Result.push_back(i + 1);
        }
    }
    return Result;
}

int main()
{
    solution({ 1, 2, 3, 4, 5 });
}

