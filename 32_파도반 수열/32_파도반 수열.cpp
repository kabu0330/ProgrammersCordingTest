#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> inputs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }

    size_t dp[101] = {};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for (int i = 6; i < 101; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
       //dp[i] = dp[i - 1] + dp[i - 5]; 이것도 가능
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[inputs[i]] << "\n";
    }
}

