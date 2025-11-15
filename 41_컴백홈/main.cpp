#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;
int arr[6][6] = {};
int visited[6][6] = {};

// 전역 변수
int r, c, k;

int targetY, targetX;
int cnt;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void solve(int y, int x, int depth)
{
	if (y == targetY && x == targetX && k == depth)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		solve(ny, nx, depth + 1);
		visited[ny][nx] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;

	targetY = 0;
	targetX = c - 1;

	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			char ch;
			cin >> ch;
			if (ch == 'T')
			{
				visited[y][x] = true;
			}
		}
	}

	if (r > 0)
	{
		visited[r - 1][0] = true;
	}

	solve(r - 1, 0, 1);


	cout << cnt;
}

