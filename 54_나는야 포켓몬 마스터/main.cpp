#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cctype>

#define endl '\n'

using namespace std;

// 전역 변수
int n;
int m;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

	cin >> n >> m;

	vector<string> vec(n + 1);
	unordered_map<string, int> hash;
	hash.reserve(n);

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		
		vec[i] = str;
		hash.emplace(str, i);
	}
	
	while (m--)
	{
		string str;
		cin >> str;

		if (isdigit(str[0]))
		{
			int idx = stoi(str);
			cout << vec[idx] << endl;
		}
		else
		{
			cout << hash[str] << endl;
		}
	}

}

