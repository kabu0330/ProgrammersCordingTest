#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n;
vector<vector<int>> matrix;
int visited[26][26];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1,  -1 };

int dfs(int y, int x)
{
	int token = 1;
	
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dy[i] + x;
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (matrix[ny][nx] == 0 || visited[ny][nx] == true) continue;

		token += dfs(ny, nx);
	}

	return token;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	matrix.resize(n + 1);
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(n + 1);
	}
	for (int y = 0; y < n; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < n; x++)
		{
			matrix[y][x] = str[x] - '0';
		}
	}

	vector<int> ret;
	int cnt = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (matrix[y][x] == 1 && visited[y][x] == false)
			{
				++cnt;
				ret.push_back(dfs(y, x));
			}
		}
	}

	// 오름차순 정렬
	sort(ret.begin(), ret.end());

	// 출력
	cout << cnt << '\n';

	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << '\n';
	}

}

