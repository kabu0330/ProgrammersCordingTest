#include <iostream>

using namespace std;

int n, m;

#define MAX_SIZE 501

int matrix[MAX_SIZE][MAX_SIZE] = {};
bool visited[MAX_SIZE][MAX_SIZE] = {false};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int dfs(int y, int x)
{
	visited[y][x] = true;
	int area = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (0 > ny || 0 > nx || ny >= n || nx >= m) continue;
		if (visited[ny][nx] || matrix[ny][nx] == 0) continue;

		area += dfs(ny, nx);
	}

	return area;
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

	int maxArea = 0;
	int paintCnt = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!visited[y][x] && matrix[y][x] == 1)
			{
				++paintCnt;
				maxArea = max(maxArea, dfs(y, x));
			}
		}
	}

	cout << paintCnt << '\n';
	cout << maxArea;
	
}
