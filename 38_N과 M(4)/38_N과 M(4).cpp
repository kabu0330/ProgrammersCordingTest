#include <iostream>

using namespace std;

int n, m;
int arr[10] = {};
int used[10] = {};

void backtracking(int k, int startNum)
{
    if (k == m)
    {
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = startNum; i <= n; i++)
    {
        arr[k] = i;
        backtracking(k + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    backtracking(0, 1);
}
