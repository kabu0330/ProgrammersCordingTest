
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int counts[100001] = {};

vector<int> solution(string s) {
    vector<int> answer;

    string numStr;
    for (const auto& str : s)
    {
        if (isdigit(str))
        {
            numStr += str;
        }
        else
        {
            if (!numStr.empty())
            {
                counts[stoi(numStr)]++;
                numStr.clear();
            }
        }
    }

    vector<pair<int, int>> freqPairs;
    for (int i = 1; i <= 100000; i++)
    {
        if (counts[i] > 0)
        {
            freqPairs.push_back({ counts[i], i });
        }
    }

    sort(freqPairs.rbegin(), freqPairs.rend());

    for (const auto& p : freqPairs)
    {
        answer.push_back(p.second);
    }

    return answer;
}

int main()
{
    string str = "{{2}, {2,1}, {2,1,3}, {2,1,3,4}}";
    solution(str);
}
