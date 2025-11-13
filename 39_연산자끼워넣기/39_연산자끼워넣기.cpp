
#include <iostream>
#include <climits>
#include <numeric>

using namespace std;

int n;
int arr[101] = {};

// + - * /
int operCount[4] = {};

enum EOperator
{
    Add,
    Subtract,
    Multiply,
    Divide
};

int minValue = INT_MAX;
int maxValue = INT_MIN;

void backtracking(int result, int idx)
{
    if (idx == n)
    {
        if (minValue > result)
        {
            minValue = result;
        }
        if (maxValue < result)
        {
            maxValue = result;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operCount[i] > 0)
        {
            operCount[i]--;
            if (i == Add) // 덧셈
            {
                backtracking(result + arr[idx], idx + 1);
            }
            else if (i == Subtract) // 뺄셈
            {
                backtracking(result - arr[idx], idx + 1);
            }
            else if (i == Multiply)
            {
                backtracking(result * arr[idx], idx + 1);
            }
            else if (i == Divide)
            {
                backtracking(result / arr[idx], idx + 1);
            }
            operCount[i]++;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> operCount[i];
    }

    backtracking(arr[0], 1);

    cout << maxValue << '\n' << minValue;
    
}
