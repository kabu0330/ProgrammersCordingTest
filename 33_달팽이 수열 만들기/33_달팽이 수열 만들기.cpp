
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n)
{
	// n x n 행렬을 만든다.
	vector<vector<int>> matrix(n, vector<int>(n, 0));

	int x = 0, y = 0;
	
	// 0 : 오른쪽, 1 : 아래, 2 : 왼쪽, 3: 위
	int dir = 0;

	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1, 0 };

	for (int i = 1; i <= n*n; i++)
	{
		matrix[y][x] = i;

		// 다음 이동 위치 계산
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 검사
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || matrix[ny][nx] != 0)
		{
			dir = (dir + 1) % 4;
		}

		y += dy[dir];
		x += dx[dir];
	}

	return matrix;
}

int main()
{
	int n = 4;
	vector<vector<int>> result = solution(n);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
}

