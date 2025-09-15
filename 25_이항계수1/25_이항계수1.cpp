#include <iostream>

using namespace std;

int n, k;

int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	cin >> n >> k;
	
	int n_result = factorial(n);
	int k_result = factorial(k);

	int result = n_result / (k_result * factorial(n - k));
	cout << result;
}

