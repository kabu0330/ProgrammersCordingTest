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
	for (size_t i = 1; i <= n; i++)
	{
		q.push(i);
	}

	cout << "<";

	while (true)
	{
		int killIdx = k - 1;

		while (killIdx > 0)
		{
			int cur = q.front();
			q.pop();
			q.push(cur);
			killIdx--;
		}
		
		int idx = q.front();
		q.pop();

		cout << idx;

		if (false == q.empty())
		{
			cout << ", ";
		}
		else
		{
			break;
		}
	}



	cout << ">" << endl;

}

