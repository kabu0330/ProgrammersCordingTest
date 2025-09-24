

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<string> board;
int min_repaint = INT_MAX;

int check(int startY, int startX)
{
	int repaint = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			int currentY = startY + y;
			int currentX = startX + x;
			if ((y + x) % 2 == 0)
			{
				if (board[currentY][currentX] != 'W')
				{
					++repaint;
				}
			}
			else
			{
				if (board[currentY][currentX] != 'B')
				{
					++repaint;
				}
			}
		}
	}
	
	return min(repaint, 64 - repaint);
}

void solve()
{
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int repaint = check(i, j);
			if (repaint < min_repaint)
			{
				min_repaint = repaint;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	board.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	solve();

	cout << min_repaint;
}

