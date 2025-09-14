
#include <iostream>

using namespace std;

int result = 1;
void solve(int n)
{
    if (n == 0)
    {
        cout << result;
        return;
    }
    
    result *= n;
    solve(n - 1);
}


int main()
{
    int n;
    cin >> n;
    
    if (0 >= n)
    {
        cout << 1;
        return 0;
    }
    
    solve(n);
    //int result = 1;
    //for (int i = 1; i <= n ; i++)
    //{
    //    result *= i;
    //}
    //cout << result;
}
