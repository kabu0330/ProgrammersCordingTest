#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) 
{
    std::sort(citations.begin(), citations.end(), std::greater<>());
    int h = 0; // ÀÎ¿ëÈ½¼ö

    int n = citations.size();
    for (int i = 0; i < n; i++)
    {
        int Value = citations[i];
        int Index = i + 1;
        if (Value >= Index)
        {
            h = Index;
        }
        else
        {
            break;
        }
    }
    return h;
}