
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;

    unordered_map<string, int> wantMap;
    for (int i = 0; i < want.size(); i++)
    {
        wantMap[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size() - 9; i++)
    {
        unordered_map<string, int> discount_10d;

        for (int j = i; j < 10 + i; j++)
        {
            discount_10d[discount[j]]++;
        }

        if (wantMap == discount_10d)
        {
            answer++;
        }
    }
    
    return answer;
}

int solution2(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    unordered_map<string, int> wantMap;
    for (int i = 0; i < want.size(); i++)
    {
        wantMap[want[i]] = number[i]; // 품목과 수량 저장
    }

	unordered_map<string, int> discount_set;
    for (int i = 0; i < 9; i++)
    {
        discount_set[discount[i]]++; // 9일치 할인 품목 저장
    }

    for (int i = 9; i < discount.size(); i++) // 10일차부터 마지막날까지
    {
        discount_set[discount[i]]++; // 10번째 할인 품목 추가
        if (wantMap == discount_set) // 키-값이 모두 일치하면
        {
            answer++;
        }
        if (--discount_set[discount[i - 9]] == 0) // 첫 날 할인 품목 삭제
        {
            discount_set.erase(discount[i - 9]); // 값이 0이면 key 삭제
        }
    }

    return answer;
}

int main()
{
    vector<string> want0 = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> number0 = { 3, 2, 2, 2, 1 };
    vector<string> discount0 = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    cout << solution(want0, number0, discount0) << endl;
    cout << solution2(want0, number0, discount0) << endl;

    vector<string> want1 = { "apple" };
    vector<int> number1 = { 10 };
    vector<string> discount1 = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };

    cout << solution(want1, number1, discount1) << endl;
    cout << solution2(want1, number1, discount1) << endl;
}
