
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8] = {};

void solve(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[idx] = i;
        solve(idx + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    solve(0);
}

