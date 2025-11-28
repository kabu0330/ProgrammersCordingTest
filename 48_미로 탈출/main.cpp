#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


#define endl '\n'

using namespace std;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int solution(vector<string> maps)
{
	pair<int, int> start;
	for (int y = 0; y < maps.size(); ++y)
	{
		bool found = false;
		string row = maps[y];
		for (int i = 0; i < row.size(); i++)
		{
			if (row[i] == 'S')
			{
				start.first = y;
				start.second = i;
				found = true;
				break;
			}
		}
		if (found) break;
	}
	
	queue<pair<int, int>> q;
	q.push(start);

	vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), false));
	visited[start.first][start.second] = true;
	int cnt = -1;
	bool foundLever = false;
	int curY, curX;

	while (!q.empty())
	{
		curY = q.front().first;
		curX = q.front().second;
		q.pop();

		++cnt;
		if (maps[curY][curX] == 'L')
		{
			foundLever = true;
			break;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
			if (visited[ny][nx] || maps[ny][nx] == 'X') continue;
			
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	if (foundLever == false)
	{
		return -1;
	}

	q.empty();
	q.push({ curY, curX });
	--cnt;

	while (!q.empty())
	{
		curY = q.front().first;
		curX = q.front().second;
		q.pop();

		++cnt;
		if (maps[curY][curX] == 'E') break;

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
			if (visited[ny][nx] || maps[ny][nx] == 'X') continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<string> input = {"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};


	int ret = solution(input);
	cout << ret;

}

