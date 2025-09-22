
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;	

	for (int i = 1; i < n; i++)
	{
		int digit = i;
		int arr[8] = {};
		int idx = 0;

		if (i == 197)
		{
			int a = 0;
		}

		while (digit > 0)
		{
			arr[idx] = digit % 10;
			digit /= 10;
			++idx;
		}

		int sum_arr = 0;
		for (int i = 0; i < 8; i++)
		{
			sum_arr += arr[i];
		}

		int result = i + sum_arr;
		if (result == n)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}

