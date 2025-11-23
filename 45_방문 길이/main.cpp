#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;


int solution(string dirs)
{
	int ret = 0;

	// 처음 가 본 간선의 개수를 구하기
	// 간선을 체크하는 방법 : 차원을 하나 더 늘린다.
	int visited[11][11][4];
	::fill(&visited[0][0][0], &visited[0][0][0] + 11 * 11 * 4, 0);

	int curX = 5;
	int curY = 5;
	
	for (int i = 0; i < dirs.size(); i++)
	{
		char ch = dirs[i];
		int dy, dx, dir;
		if (ch == 'U')
		{
			dy = curY - 1;
			dx = curX;
			dir = 0;
		}
		else if (ch == 'D')
		{
			dy = curY + 1;
			dx = curX;
			dir = 1;
		}
		else if (ch == 'R')
		{
			dy = curY;
			dx = curX + 1;
			dir = 2;
		}
		else
		{
			dy = curY;
			dx = curX - 1;
			dir = 3;
		}

		if (dy < 0 || dx < 0 || dy > 10 || dx > 10) continue;

		if (!visited[curY][curX][dir])
		{
			visited[curY][curX][dir] = true;

			// 역방향 계산
			int reversDir;
			if (dir == 0) reversDir = 1;      // U ↔ D
			else if (dir == 1) reversDir = 0;
			else if (dir == 2) reversDir = 3; // R ↔ L
			else reversDir = 2;

			// 다음 위치에서 역방향 간선 체크
			visited[dy][dx][reversDir] = true;
			++ret;
		}

		curY = dy;
		curX = dx;
	}

	cout << ret;
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input = "ULURRDLLU";


	int ret = solution(input);
}

