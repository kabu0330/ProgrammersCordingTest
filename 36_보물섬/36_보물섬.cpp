
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

char matrix[51][51] = {};
int visited[51][51] = {};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int cnt = 0;

void bfs(int y, int x)
{
	// 처음 시작할 때 방문처리를 리셋하여 현재 위치 기준으로 최단거리가 얼마나 큰지 본다.
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0); 

	queue<pair<int, int>> q;
	q.push({ y, x });

	visited[y][x] = true; // 방문처리

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
			if (visited[ny][nx] || matrix[ny][nx] == 'W') continue;

			visited[ny][nx] = visited[cy][cx] + 1; // 몇 번째에 도달했는지 체크
			q.push({ ny, nx }); 

			cnt = max(cnt, visited[ny][nx]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int j = 0; j < n; j++)
	{
		string str;
		cin >> str;
		for (int k = 0; k < str.size(); k++)
		{
			matrix[j][k] = str[k];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (matrix[y][x] == 'L') // 여기서 방문체크 하지 않고 땅이면 모두 돌아본다.
			{
				bfs(y, x);
			}
		}
	}

	cout << cnt - 1; // 처음 시작은 방문 처리를 위해서 1부터 시작했지만, 문제에선 나 자신은 제외했으므로 -1 처리
}

