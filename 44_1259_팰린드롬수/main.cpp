#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'

using namespace std;

// 전역 변수
string n;
vector<int> vec;
stack<int> stk;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> n && n != "0")
	{
		vec.clear();
		stk.empty();

		for (int i = 0; i < n.size(); i++)
		{
			int value = n[i] - '0';
			vec.push_back(value);
			stk.push(value);
		}

		bool success = true;
		for (int i = 0; i < vec.size() / 2; i++)
		{
			int value = stk.top();
			stk.pop();
			if (vec[i] != value)
			{
				success = false;
				break;
			}
		}
		
		if (success)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
	}
}

