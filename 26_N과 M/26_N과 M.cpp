
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 1; i <= n; i++)
	{
		vec[i - 1] = i;
	}

	do
	{
		if (true)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				cout << vec[i] << " ";
			}
			cout << "\n";
		}
	} while (next_permutation(vec.begin(), vec.end()));

}
