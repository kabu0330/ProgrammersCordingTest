
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int matrix[301][301] = {};
int visited[301][301] = {};

pair<int, int> junan, dest;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int cnt = 0;


void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true; // 방문 처리

	while (matrix[dest.first][dest.second] != 0) // 2라운드 : 점프 횟수
	{
		queue<pair<int, int>> temp;
		++cnt; // 점프 횟수

		while (q.size()) // 1라운드 : 한 번의 점프로 인한 충격파 범위 계산
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (visited[ny][nx]) continue;

				visited[ny][nx] = cnt;
	
				if (matrix[ny][nx] != 0) // 0이 아니면 사람이 존재하므로
				{
					matrix[ny][nx] = 0; // 사람을 쓰러뜨린다.
					temp.push({ ny, nx }); // 다음 점프에 쓰러진 사람 기준으로 다시 충격파가 퍼져나간다.
				}
				else // 빈 공간이면 계속 푸시, 점프 한 번에 도달하는 모든 빈 공간을 푸시하므로 충격파 범위 계산
				{
					q.push({ ny, nx });
				}
			}
		}

		q = temp; // 다음 점프에서 쓰러진 사람 위치에서 충격파가 퍼져 나간다.
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> junan.first >> junan.second >> dest.first >> dest.second;

	--junan.first; --junan.second; --dest.first; --dest.second;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			char ch = str[j];
			matrix[i][j] = ch - '0';

		}
	}

	bfs(junan.first, junan.second);

	cout << visited[dest.first][dest.second];
}
