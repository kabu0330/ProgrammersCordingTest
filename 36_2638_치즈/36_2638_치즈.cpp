#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt = 0;

int matrix[101][101] = {};
int visited[101][101] = {};

int dy[4] = { 1, -1, 0 ,0 };
int dx[4] = { 0, 0, 1, -1 };

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] || matrix[ny][nx] == 1) continue;

		dfs(ny, nx);
	}
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

	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		dfs(0, 0); // 가장자리부터 돌면서 외부를 방문(1) 처리
		
		vector<pair<int, int>> meltingCheese;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (matrix[y][x] == 1)
				{
					int air = 0;
					for (int k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (visited[ny][nx] == 1)
						{
							++air;
						}
					}

					if (air >= 2) // 상하좌우 접촉면이 2 이상이면 녹는다.
					{
						meltingCheese.push_back({ y, x });
					}
				}
			}
		}

		if (meltingCheese.empty())
		{
			break;
		}

		++cnt; 

		for (auto pos : meltingCheese) // 치즈가 녹으면 외부(0) 처리
		{
			matrix[pos.first][pos.second] = 0;
		}
	}

	cout << cnt << '\n';
}

