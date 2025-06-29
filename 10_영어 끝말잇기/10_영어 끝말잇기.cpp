#include "another.h"

#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0, 0 };
    unordered_set<string> hash;

    string prevStr = " ";
    for (int i = 0; i < words.size(); i++)
    {
        string str = words[i];
        char a = *(prevStr.end() - 1);
        char b = *words[i].begin();
        if (prevStr == " " || hash.find(str) == hash.end() && a == b)
        {
            hash.insert(str);
            prevStr = str;
        }
        else
        {
            int num = i % n + 1;
            
            int idx = i / n + 1;

            answer = { num, idx };
            return answer;
        }
    }

    return answer;
}

int main()
{
    int n = 2;
    vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    vector<int> result = solution(n, words);
    vector<int> result2 = solution2(n, words);
}

