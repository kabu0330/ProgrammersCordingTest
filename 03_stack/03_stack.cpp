#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<typename T>
void Reverse(vector<T>& Vec)
{
    stack<T> Stack;
    for (T Value : Vec)
    {
        Stack.push(Value);
    }

    for (size_t i = 0; i < Vec.size(); i++)
    {
        Vec[i] = Stack.top();
        Stack.pop();
    }
}

int main()
{
    string Str1 = "Hello";
    string Str2 = "ALGORITHM";

    vector<int> Vec1{ 10, 20, 30, 40, 50 };

    Reverse<int>(Vec1);

    for (size_t i = 0; i < Vec1.size(); i++)
    {
        cout << Vec1[i] << endl;
    }

}
