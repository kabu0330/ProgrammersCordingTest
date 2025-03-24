#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    int Day = startday;
    for (int i = 0; i < schedules.size(); i++)
    {
        int Count = 0;
        int DeadTime = schedules[i] + 10;
        int Minute = DeadTime % 100;
        if (59 < Minute)
        {
            DeadTime += 100;
            DeadTime -= 60;
        }
        for (int j = 0; j < 7; j++)
        {
            startday++;

            if (7 < startday) // 일요일이면
            {
                startday = 1;        
            }
            else if (6 < startday) // 주말은 생략
            {
            }
            else
            {
                int WorkStartTime = timelogs[i][j];
                if (DeadTime >= WorkStartTime)
                {
                    Count++;
                }
            }

            if (6 == j)
            {
                if (5 == Count)
                {
                    ++answer;
                    startday = Day;
                    continue;
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> schedules = { 730, 855, 700, 720 };
    vector<vector<int>> timelogs;
    timelogs.push_back({ 710, 700, 650, 735, 700, 931, 912 });
    timelogs.push_back({ 908, 901, 805, 815, 800, 831, 835 });
    timelogs.push_back({ 705, 701, 702, 705, 710, 710, 711 });
    timelogs.push_back({ 707, 731, 859, 913, 934, 931, 905 });
    int startday = 1;

    int Result = solution(schedules, timelogs, startday);
    std::cout << Result << std::endl;
}

