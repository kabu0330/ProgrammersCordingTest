
#include <iostream>

using namespace std;

void solve(int n)
{
    int mod = n % 5;
    if (mod == 0)
    {
        cout << n / 5;
        return;
    }

    if (mod == 3)
    {
        //          5 kg 개수 + 3kg 1개
        cout << ((n - 3) / 5) + 1;
        return;
    }
    
    for (int i = 1; i <= (n / 5); i++)
    {
        // 3 = 17 / 5 ... 2
        int value = n / 5;
        int five_sugar = (value - i) * 5;
        if ((n - five_sugar) % 3 == 0)
        {
            int three_sugar = (n - five_sugar) / 3;
            cout << (five_sugar / 5) + three_sugar;
            return;
        }
    }

    cout << -1;
}

int main()
{
    int n;
    cin >> n;

    solve(n);
   
}

