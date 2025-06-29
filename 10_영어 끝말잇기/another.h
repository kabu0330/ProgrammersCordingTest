#pragma once



#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution2(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> usedWords;

    usedWords.insert(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        auto value = usedWords.insert(words[i]).second;
        char front = words[i].front();
        char back = words[i - 1].back();
        if (!usedWords.insert(words[i]).second)
        {
            if (words[i].front() != words[i - 1].back())
            {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                return answer;
            }

        }
    }
    
    return answer;
}
