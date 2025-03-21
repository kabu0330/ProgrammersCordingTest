#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//vector<int> solution(vector<int> progresses, vector<int> speeds) 
//{
//    vector<int> answer;
//    std::queue<int> progressesQueue;
//    std::queue<int> speedsQueue;
//
//    for (size_t i = 0; i < progresses.size(); i++)
//    {
//        progressesQueue.push(progresses[i]);
//        speedsQueue.push(speeds[i]);
//    }
//
//    int Day = 0;
//    int Count = 0;
//    while (true)
//    {
//        if (true == progressesQueue.empty())
//        {
//            answer.push_back(Count);
//            return answer;
//        }
//        int& CurValue = progressesQueue.front();
//        int Speed = speedsQueue.front();
//
//        if (100 > CurValue)
//        {
//            for (int i = 0; i < Day; i++)
//            {
//                CurValue += Speed;
//            }
//        }
//
//        if (100 <= CurValue)
//        {
//            progressesQueue.pop();
//            speedsQueue.pop();
//            ++Count;
//            continue;
//        }
//
//        if (0 != Count)
//        {
//            answer.push_back(Count);
//            Count = 0;
//        }
//
//        while (100 > CurValue)
//        {
//            CurValue += Speed;
//            ++Day;
//        }
//    }
//}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

         if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}

int main()
{
    std::vector<int> Progresses = { 95, 90, 99, 99, 80, 99 };
    std::vector<int> Speeds = { 1, 1, 1, 1, 1 ,1 };
    std::vector<int> Result = solution(Progresses, Speeds);
    std::cout << "Hello World!\n";
}
