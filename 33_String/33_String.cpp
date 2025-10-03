
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int repeat;
		string str;
		cin >> repeat >> str;
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = 0; j < repeat; j++)
			{
				cout << str[i];
			}
		}
		cout << endl;
	}

}

