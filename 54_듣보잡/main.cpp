#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define endl '\n'

using namespace std;

// 전역 변수
int n, m;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	unordered_set<string> hash;
	hash.reserve(n);

	while (n--)
	{
		string str;
		cin >> str;
		
		hash.insert(str);
	}

	int cnt = 0;
	vector<string> vec;
	while (m--)
	{
		string str;
		cin >> str;

		if (hash.find(str) != hash.end())
		{
			++cnt;
			vec.push_back(str);
		}
	}
	
	sort(vec.begin(), vec.end());

	cout << cnt << endl;

	for (const string& ele : vec)
	{
		cout << ele << endl;
	}

}

