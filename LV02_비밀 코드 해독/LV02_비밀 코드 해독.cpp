#include <iostream>
#include <vector>

// 비밀번호는 5개의 숫자, 오름차순으로 정렬되어있고, n까지의 숫자만 존재, m번의 시도, return 응답 중 중복되지 않은 숫자들
using namespace std;

//            max      입력한 정수 5개    ,   응답
int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    int answer = 0;

    
    

    return answer;
}

int main()
{
    vector<vector<int>> Q;
    Q.resize(100);
    for (int i = 0; i < Q.size(); i++)
    {
        Q[i].reserve(5);
    }

    Q.push_back({ 1, 2, 3, 4, 5 });
    Q.push_back({ 6, 7, 8, 9, 10 });
    Q.push_back({ 3, 7, 8, 9, 10 });
    Q.push_back({ 2, 5, 7, 9, 10 });
    Q.push_back({ 3, 4, 5, 6, 7 });

    vector<int> Ans = { 2, 3, 4, 3, 3 };

    int Result = solution(10, Q, Ans);
    std::cout << Result << std::endl;
}

