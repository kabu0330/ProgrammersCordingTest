#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>


#define endl '\n'

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

char arr[24][24] = {};
int visited[150] = {};

// 전역 변수
int iy, ix;
int result = 0;


void solve(int y, int x, int cnt)
{
	result = ::max(result, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= iy || nx >= ix) continue;
		if (visited[arr[ny][nx]]) continue;

		visited[arr[ny][nx]] = true;
		solve(ny, nx, cnt + 1);
		visited[arr[ny][nx]] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> iy >> ix;
	for (int y = 0; y < iy; y++)
	{
		for (int x = 0; x < ix; x++)
		{
			char ch;
			cin >> ch;
			arr[y][x] = ch;
		}
	}
	visited[arr[0][0]] = true;
	solve(0, 0, 1);

	cout << result;

}

