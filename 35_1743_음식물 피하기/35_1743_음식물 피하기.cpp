#include <iostream>
#include <queue>

using namespace std;

int matrix[101][101] = {};
bool visited[101][101] = {};

int n, m, k;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(int y, int x)
{
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y, x });

	int cnt = 0;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		++cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (0 > ny || 0 > nx || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || matrix[ny][nx] == 0) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		matrix[y - 1][x - 1] = 1;
	}

	// 쓰레기 개수 찾기
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 쓰레기를 발견하면 붙어있는지 체크
			if (!visited[i][j] && matrix[i][j] == 1)
			{
				cnt = max(cnt, bfs(i, j));
			}
		}
	}

	cout << cnt;
}
