
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using namespace std;

bool compareCount(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer(id_list.size(), 0);
    //            신고자,  인덱스, 신고완료 발송 횟수
    unordered_map<string, pair<int, int>> ids; // result의 인덱스 탐색용
    for (int i = 0; i < id_list.size(); i++)
    {
        ids[id_list[i]] = { i, 0 };
    }

    unordered_map<string, unordered_set<string>> reportFrom; // 피의자, 신고자들
    unordered_map<string, int> datas; // 피의자, 신고당한 횟수
    for (int i = 0; i < report.size(); i++)
    {
        stringstream sstream(report[i]);
        string first_id, second_id;
        sstream >> first_id;
        sstream >> second_id;

        if (reportFrom[second_id].find(first_id) == reportFrom[second_id].end())
        {
            reportFrom[second_id].insert(first_id);
            ++datas[second_id];
        }
    }

    vector<pair<string, int>> result(datas.begin(), datas.end());
    sort(result.begin(), result.end(), compareCount);

    for (int i = 0; i < result.size(); i++) // 신고횟수가 큰 순으로 순회
    {
        string suspect = result[i].first;
        int count = result[i].second;
        if (count >= k)
        {
            for (auto& caller : reportFrom[suspect])
            {
                ++ids[caller].second;
            }
        }
        else // 내림차순 탐색이므로 k보다 작으면 더 이상 반복할 필요가 없다.
        {
            break;
        }
    }

    for (auto& caller : ids)
    {
        int idx = caller.second.first;
        int count = caller.second.second;
        answer[idx] = count;
    }

    return answer;
}

int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k = 2;
    vector<int> result = solution(id_list, report, k);

    vector<string> id_list2 = { "con", "ryan" };
    vector<string> report2 = { "ryan con", "ryan con", "ryan con", "ryan con" };
    int k2 = 3;
    vector<int> result2 = solution(id_list2, report2, k2);
}
