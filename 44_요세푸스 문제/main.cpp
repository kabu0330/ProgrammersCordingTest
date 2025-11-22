#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

// 전역 변수
int n, k;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	
	vector<int> vec;
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			int value = q.front();
			q.pop();
			q.push(value);
		}
		int value = q.front();
		q.pop();
		vec.push_back(value);
	}

	cout << "<";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i == vec.size() - 1)
		{
			cout << vec[i] << ">";
		}
		else
		{
			cout << vec[i] << ", ";
		}
	}
}

