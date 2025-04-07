#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution_AnotherApproach(vector<int> priorities, int location)
{
    std::queue<int> Printer;
    std::vector<int> Sorted;
    for (int i = 0; i < priorities.size(); i++)
    {
        Printer.push(i);
    }

    while (false == Printer.empty())
    {
        int NowIndex = Printer.front();
        Printer.pop();
        if (priorities[NowIndex] != *max_element(priorities.begin(), priorities.end()))
        {
            // 우선순위가 높은 값이 아니라면
            Printer.push(NowIndex);
        }
        else // 우선순위가 높은 값이라면
        {
            Sorted.push_back(NowIndex);
            priorities[NowIndex] = 0;
        }
	}

	for (int i = 0; i < Sorted.size(); i++)
	{
		if (Sorted[i] == location)
		{
			return i + 1;
		}
	}
}

