
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    

    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dp[i];
    }
    int max_value = dp[0];
    int current_value = 0;
    for (int i = 0; i < n; i++)
    {
        current_value += dp[i];
        
        if (current_value > max_value)
        {
            max_value = current_value;
        }

        if (current_value < 0)
        {
            current_value = 0;
        }
    }

    cout << max_value;
}
