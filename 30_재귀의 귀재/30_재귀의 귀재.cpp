
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int recursive(const string& str, int start, int end, int& count)
{
	if (start >= end)
	{
		return 1;
	}

	if (str[start] == str[end])
	{
		return recursive(str, start + 1, end - 1, ++count);
	}
	else
	{
		return 0;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> answers(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		int count = 1;
		int result = recursive(str, 0, str.size() - 1, count);
		answers[i] = make_pair( result, count );
	}
	
	for (const auto& answer : answers)
	{
		std::cout << answer.first << " " << answer.second << "\n";
	}
}
