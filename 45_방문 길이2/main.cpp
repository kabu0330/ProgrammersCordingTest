#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define endl '\n'

using namespace std;

int toIdx(char ch)
{
	switch (ch)
	{
	case 'R': return 0;
	case 'L': return 1;
	case 'U': return 2;
	case 'D': return 3;
	}
}

int solution(string dirs)
{
	int ret = 0;

	char ch;
	int x = 0, y = 0, ty, tx, dy[] = { 0,0,1, -1 }, dx[] = { 1, -1, 0, 0 }, idx, a, b;
	set<pair<int, int>> ans;

	for (int i = 0; i < dirs.length(); i++)
	{
		ch = dirs[i];
		idx = toIdx(ch);
		tx = x + dx[idx];
		ty = y + dy[idx];
		if (!(-5 <= ty && ty <= 5 && -5 <= tx && tx <= 5)) continue;
		
		a = x * 10000 + y;
		x = tx;
		y = ty;
		b = x * 10000 + y;
		if (ans.find({a, b}) == ans.end() && ans.find({b, a}) == ans.end())
		{
			ans.insert({ a, b });
		}
	}

	return ret = (int)ans.size();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	string input = "ULURRDLLU";


	int ret = solution(input);
}

