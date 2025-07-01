
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<string, int> total;
unordered_map<string, string> parent;

void div(const string& target, int val)
{
    int value = round(val * 0.9f);
    int remain = val - value;

    if (parent[target] == "-")
    {
        total[target] += value;
        total["center"] += remain;
    }
    else
    {
        total[target] += value;
        div(parent[target], remain);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    string center = "center";
    total[center] = 0;
    parent[center] = "-";
    
    for (int i = 0; i < enroll.size(); i++)
    {
        total[enroll[i]] = 0;
    }
    
    for (int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
    }

    // 판매원을 추천한 사람들에게 수익의 10%를 지속적으로 배분해야 한다.
    for (int i = 0; i < seller.size(); i++)
    {
        int money = amount[i] * 100;
        string cur_name = seller[i];

        //div(cur_name, val);
        while (money > 0 && cur_name != "-")
        {
            int to_distribute = money / 10;
            total[cur_name] += money - to_distribute;
            
            if (parent.find(cur_name) != parent.end())
            {
                cur_name = parent[cur_name];
            }
            else
            {
                break;
            }
            
            money = to_distribute;
        }
    }

    vector<int> answer(enroll.size(), 0);
    for (int i = 0; i < answer.size(); i++)
    {
        answer[i] = total[enroll[i]];
    }

    return answer;
}

int main()
{
    vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"  };
    vector<string> seller = { "sam", "emily", "jaimie", "edward" };
    vector<int> amount = { 2, 3, 5, 4 };
    vector<int> result = solution(enroll, referral, seller, amount);
}
