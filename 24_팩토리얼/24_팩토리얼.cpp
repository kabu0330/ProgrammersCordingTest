
#include <iostream>

using namespace std;

int n;
size_t result = 1;

void solve(int k)
{
	if (k == 0)
	{
		return;
	}

	result *= k;
	solve(k - 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	solve(n);
	cout << result;
}

