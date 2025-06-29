
#include <iostream>


#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "Yes";
    queue<string> queue1;
    queue<string> queue2;
    
    for (int i = 0; i < cards1.size(); i++)
    {
        queue1.push(cards1[i]);
    }
    for (int i = 0; i < cards2.size(); i++)
    {
        queue2.push(cards2[i]);
    }

    for (int i = 0; i < goal.size(); i++)
    {
        string str = goal[i];
        
        if (false == queue1.empty() && str == queue1.front())
        {
            queue1.pop();
        }
        else if (false == queue2.empty() && str == queue2.front())
        {
            queue2.pop();
        }
        else
        {
            answer = "No";
            break;
        }
    }
    
    return answer;
}

int main()
{
    vector<string> cards1 = { "i", "water", "drink" };
    vector<string> cards2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };
    string result = solution(cards1, cards2, goal);
}

