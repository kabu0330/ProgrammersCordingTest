
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

int n, m;

void backtracking(int start)
{
	if (vec.size() == m)
	{
		for (const int value : vec)
		{
			cout << value << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		vec.push_back(i);
		backtracking(i + 1);
		vec.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	backtracking(1);
}

