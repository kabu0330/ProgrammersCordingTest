
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//  y, x
int n, m;
vector<vector<int>> graph;
vector<vector<int>> visited;

// 1로 연결된 길이의 최대 크기

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int maxPaint = 0;
int paint = 0;

bool isValid(int y, int x)
{
	return 0 <= y && 0 <= x && n > y && m > x;
}

void solve(int cy, int cx, int& paint)
{
	visited[cy][cx] = 1;

	queue<pair<int, int>> q;
	q.push({ cy, cx });

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		++paint;

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (isValid(ny, nx))
			{
				if (!visited[ny][nx])
				{
					if (graph[ny][nx] == 1)
					{
						visited[ny][nx] = 1;
						q.push({ ny, nx });
					}
				}
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	graph.assign(n, vector<int>(m, -1));
	visited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	int paintCount = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!visited[y][x] && graph[y][x] != 0)
			{
				int paint = 0;
				solve(y, x, paint);
				if (paint > maxPaint)
				{
					maxPaint = paint;
				}
				++paintCount;
			}
		}
	}

	cout << paintCount << '\n';
	cout << maxPaint;
}
