#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define SIZE 26

int matrix[SIZE][SIZE] = {};
bool visited[SIZE][SIZE] = {};

int n;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(int y, int x)
{
	int cnt = 0;
	visited[y][x] = true;
	
	queue<pair<int, int>> q;
	q.push({ y, x });

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

			if (0 > ny || 0 > nx || ny >= n || nx >= n) continue;
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

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int k = 0; k < str.size(); k++)
		{
			matrix[i][k] = str[k] - '0';
		}
	}
	
	int block = 0;
	vector<int> complex;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x] && matrix[y][x] == 1)
			{
				++block;
				complex.push_back(bfs(y, x));
			}
		}
	}
	
	// 오름차순 정렬
	sort(complex.begin(), complex.end());

	// 단지 수
	cout << block << '\n';

	// 건물 수가 낮은 순서대로 추력
	for (int i = 0; i < complex.size(); i++)
	{
		cout << complex[i] << '\n';
	}

}
