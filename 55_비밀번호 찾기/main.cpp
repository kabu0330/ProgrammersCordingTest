#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


#define endl '\n'

using namespace std;

// 전역 변수
int n, m;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	unordered_map<string, string> hash;
	hash.reserve(n);
	
	while (n--)
	{
		string site;
		string pw;
		cin >> site >> pw;
		hash.insert({ site, pw });
	}

	while (m--)
	{
		string site;
		cin >> site;
		if (hash.find(site) != hash.end())
		{
			cout << hash[site] << endl;
		}
	}
}

