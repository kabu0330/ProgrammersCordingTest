
#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> combi;

void combination(string src, string dst, int depth)
{
    if (dst.size() == depth)
    {
        combi[dst]++;
    }
    else
    {
        for (int i = 0; i < src.size(); i++)
        {
            combination(src.substr(i + 1), dst + src[i], depth);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;

    for (string& order : orders) // 정렬 우선
    {
        sort(order.begin(), order.end());
    }

    for (int len : course) // 코스 조합 수
    {
        for (string order : orders) // len에 맞춰 조합
        {
            combination(order, "", len);
        }

        int maxOrder = 0;
        for (auto it : combi) // 해당 코스에서 가장 주문 많은 수
        {
            maxOrder = max(maxOrder, it.second);
        }

        for (auto it : combi) // 2번 이상, 가장 주문 많았던 문자열만 추가
        {
            if (maxOrder >= 2 && it.second == maxOrder)
            {
                answer.push_back(it.first);
            }
        }

        combi.clear(); // 해당 코스 수 조합 삭제
    }
    
    sort(answer.begin(), answer.end()); // 문자열 오름차순 정렬
    return answer;
}

int main()
{
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };
    vector<string> result = solution(orders, course);

    //Scombination("abc", "", 2);
}
