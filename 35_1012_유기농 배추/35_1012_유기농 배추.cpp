
#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
int t;

int matrix[51][51] = {};
bool visited[51][51] = {};

int dy[4] = { 1, -1, 0 , 0 };
int dx[4] = { 0, 0, 1, -1 };

void bfs(int py, int px)
{
	visited[py][px] = true;
	
	queue<pair<int, int>> q;
	q.push({ py, px });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 > ny || 0 > nx || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || matrix[ny][nx] == 0) continue;

			visited[ny][nx] = true; 
			q.push({ ny, nx });
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> m >> n >> k;
		
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			matrix[y][x] = 1;
		}

		// 몇 번 bfs 함수를 호출하는지가 곧 분리된 지역의 개수
		int cnt = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (!visited[y][x] && matrix[y][x] == 1)
				{
					++cnt;
					bfs(y, x);
				}
			}
		}

		cout << cnt << '\n';

		// 다음 테스트 케이스를 위한 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}
}

