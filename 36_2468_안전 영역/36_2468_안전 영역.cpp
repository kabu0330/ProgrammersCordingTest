#include <iostream>
#include <vector>

using namespace std;

int n;
int maxHeight = 0;

int matrix[101][101] = {};
int visited[101][101] = {};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, int height)
{
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] || matrix[ny][nx] <= height) continue;

		dfs(ny, nx, height);
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] > maxHeight)
			{
				maxHeight = matrix[i][j];
			}
		}
	}
	
	int curHeight = 0;
	int maxCount = 0;
	while (curHeight < maxHeight)
	{
		// 매번 탐색할 때마다 방문 여부를 초기화해줘야 하므로 fill 사용
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		int cnt = 0;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				// 현재 높이보다 높은 지역만 돌아본다.
				if (!visited[y][x] && matrix[y][x] > curHeight)
				{
					++cnt;
					if (curHeight == 8)
					{
						int a = 0;
					}
					dfs(y, x, curHeight); // 방문 처리만 한다.
				}
			}
		}

		// 최대 영역 개수 카운팅
		if (maxCount < cnt)
		{
			maxCount = cnt;
		}

		// 물의 수위를 높인다.
		++curHeight;
	}

	cout << maxCount;
	
}


