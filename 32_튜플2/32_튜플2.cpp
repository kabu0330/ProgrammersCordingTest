
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    // 숫자가 많이 등장한 순서대로 내림차순해야 함
    // 해당 숫자가 등장한 빈도만큼 해당 인덱스에 카운팅
    int counts[100001] = {};

    // 문자열 파싱
    string num = "";
    for (const auto& ch : s)
    {
        // 숫자면 기록
        if (isdigit(ch))
        {
            num += ch;
        }
        else // 숫자가 아니면 숫자 카운트
        {
            if (!num.empty()) 
            {
                int idx = stoi(num);
                ++counts[idx];
                num.clear();
            }
        }
    }

    vector<pair<int, int>> datas;
    for (int i = 1; i < 100001; i++)
    {
        if (counts[i] > 0)
        {
            datas.push_back({counts[i], i});
        }
    }

    // 숫자가 많이 등장한 순서대로 내림차순
    sort(datas.rbegin(), datas.rend());

    // 정답 입력
    for (const auto& pair : datas)
    {
        answer.push_back(pair.second);
    }

    return answer;
}
int main()
{
    string str = "{{2}, {2,1}, {2,1,3}, {2,1,3,4}}";
    solution(str);
}

