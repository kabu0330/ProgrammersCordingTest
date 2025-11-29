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


bool bfs(int& y, int& x, int& depth, char target, const vector<string>& maps)
{
	queue<tuple<int, int, int>> q;
	q.push({ y, x, depth });
	bool visited[104][104];
	fill(&visited[0][0], &visited[0][0] + 104 * 104, false);

	while (!q.empty())
	{
		auto [cy, cx, token] = q.front();
		q.pop();

		if (maps[cy][cx] == target)
		{
			y = cy;
			x = cx;
			depth = token;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
			if (maps[ny][nx] == 'X' || visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx, token + 1 });
		}
	}
	return false;
}

int solution(vector<string> maps)
{
	int ret = 0;
	pair<int, int> start;
	for (int y = 0; y < maps.size(); ++y)
	{
		bool found = false;
		for (int i = 0; i < maps[y].size(); i++)
		{
			if (maps[y][i] == 'S')
			{
				start = pair(y, i);
				found = true;
				break;
			}
		}
		if (found == true) break;
	}

	if (false == bfs(start.first, start.second, ret, 'L', maps))
	{
		return -1;
	}
	if (false == bfs(start.first, start.second, ret, 'E', maps))
	{
		return -1;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<string> input = {"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};


	int ret = solution(input);
	cout << ret;

}

