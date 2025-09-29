
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	
	unordered_set<int> owned;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		owned.insert(data);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int find_data;
		cin >> find_data;
		if (owned.find(find_data) != owned.end())
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
}

