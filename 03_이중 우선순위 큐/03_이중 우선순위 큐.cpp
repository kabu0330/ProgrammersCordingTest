#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) 
{
    vector<int> answer(2, 0);
    std::multiset<int> Tree;
    
    for (const string& String : operations)
    {
        if ('I' == String[0]) // 삽입
        {
            int Num = std::stoi(String.substr(2));
            Tree.insert(Num);
        }
        else if ("D 1" == String) // 최댓값 삭제
        {
            if (true == Tree.empty())
            {
                continue;
            }
            std::multiset<int>::iterator MaxIter = std::prev(Tree.end());
            Tree.erase(MaxIter);
        }
        else if ("D -1" == String) // 최솟값 삭제
        {
            if (true == Tree.empty())
            {
                continue;
            }
            Tree.erase(Tree.begin());
        }
    }

    if (false == Tree.empty())
    {
        answer[0] = *Tree.begin();
        answer[1] = *std::prev(Tree.end());
    }

    return answer;
}

int main()
{
    solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
}
