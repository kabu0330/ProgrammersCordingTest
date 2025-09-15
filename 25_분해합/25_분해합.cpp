
#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int arr[8] = {};
		int idx = 0;
		int temp = i;
		while (temp > 0)
		{
			arr[idx] = temp % 10;
			temp /= 10;
			++idx;
		}

		int arr_sum = 0;
		for (int i = 0; i < 8; i++)
		{
			arr_sum += arr[i];
		}

		int result = i + arr_sum;
		if (result == n)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
}
