
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    // 피의자, 신고자들
    unordered_map<string, unordered_set<string>> reported_user; 
    unordered_map<string, int> count; // 신고자, 받은 횟수

    for (string& r : report)
    {
        stringstream ss(r);
        string user_id, reported_id;
        ss >> user_id >> reported_id;
        reported_user[reported_id].insert(user_id);
    }

    for (auto &[reported_id, user_id_lst] : reported_user)
    {
        if (user_id_lst.size() >= k)
        {
            for (const string& uid : user_id_lst)
            {
                count[uid]++;
            }
        }
    }

    vector<int> answer;
    for (string& id : id_list)
    {
        answer.push_back(count[id]);
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
