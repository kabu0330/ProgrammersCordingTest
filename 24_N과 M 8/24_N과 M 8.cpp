
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = {};
vector<int> vec;

void solve(int idx, int start)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < vec.size(); i++)
    {
        arr[idx] = vec[i];
        solve(idx + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    vec.resize(n);
    for (int i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    solve(0, 0);
}
