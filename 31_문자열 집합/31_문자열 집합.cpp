
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	unordered_set<string> str_set;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		str_set.insert(str);
	}

	int match_count = 0;
	for (int i = 0; i < m; i++)
	{
		string find_str;
		cin >> find_str;
		if (str_set.find(find_str) != str_set.end())
		{
			++match_count;
		}
	}

	cout << match_count;
}

