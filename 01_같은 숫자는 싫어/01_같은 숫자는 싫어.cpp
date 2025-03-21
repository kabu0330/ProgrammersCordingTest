#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    //for (vector<int>::reverse_iterator riter = answer.rbegin(); riter != answer.rend(); ++riter)
    //{
    //    vector<int>::iterator i = riter.base();
    //    *i = 4;
    //    i;

    //}

    //for (size_t i = arr.size() - 1;)
    for (size_t i = 0; i < arr.size(); i++)
    {
        int Value = arr[i];
        if (0 == i)
        {
            answer.push_back(Value);
            continue;
        }
        int Back = answer.back();
        if (answer.back() == Value)
        {
            continue;
        }
        answer.push_back(Value);
    }
    
    return answer;
}

int main()
{
    vector<int> Result =  solution({ 4,4,3,3,3 });
    for (int i = 0; i < Result.size(); i++)
    {
        std::cout << Result[i] << std::endl;
    }
}

