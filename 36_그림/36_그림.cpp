#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int matrix[501][501];
int visited[501][501] = {};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	
	int cnt = 1;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || matrix[ny][nx] == 0) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
			++cnt;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int cnt = 0;
	int maxArea = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!visited[y][x] && matrix[y][x] == 1)
			{
				++cnt;
				maxArea = ::max(bfs(y, x), maxArea);
			}
		}
	}

	cout << cnt << '\n';
	cout << maxArea;
}

