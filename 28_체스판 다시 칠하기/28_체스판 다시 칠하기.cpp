
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_board(int start_y, int start_x, const vector<string>& board)
{
	char first_char = board[start_y][start_x];
	char second_char;
	if (first_char == 'W')
	{
		second_char = 'B';
	}
	else
	{
		second_char = 'W';
	}

	int repaint_count = 0;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			int current_y = start_y + y;
			int current_x = start_x + x;

			if ((y + x) % 2 == 0) // 짝수는 first_char와 같아야 한다.
			{
				if (board[current_y][current_x] != first_char)
				{
					++repaint_count;
				}
			}
			else
			{
				if (board[current_y][current_x] != second_char)
				{
					++repaint_count;
				}
			}
		}
	}
	return min(repaint_count, 64 - repaint_count);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> board(n);
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	
	int min_repaint = 64;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int cur_repaint = check_board(i, j, board);
			if (cur_repaint < min_repaint)
			{
				min_repaint = cur_repaint;
			}
		}
	}
	
	cout << min_repaint;
}
