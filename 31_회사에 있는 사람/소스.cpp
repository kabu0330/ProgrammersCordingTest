#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	set<string> logs;
	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;

		if (state == "enter" && logs.find(name) == logs.end())
		{
			logs.insert(name);
		}
		else if (state == "leave" && logs.find(name) != logs.end())
		{
			logs.erase(name);
		}
	}

	auto start_iter = logs.rbegin();
	auto end_iter = logs.rend();
	for (; start_iter != end_iter; ++start_iter)
	{
		string name = *start_iter;
		cout << name << "\n";
	}
	
}