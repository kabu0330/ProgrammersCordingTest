#include <iostream>
#include <vector>

using namespace std;

bool isValid(int num, int dx, int dy, const vector<vector<int>>& board)
{
	for (int y = 0; y < board.size(); y++)
	{
		if (num == board[y][dx])
		{
			return false;
		}
	}

	for (int x = 0; x < board[0].size(); x++)
	{
		if (num == board[dy][x])
		{
			return false;
		}
	}

	int idx_x = dx / 3 * 3;
	int idx_y = dy / 3 * 3;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			int value = board[idx_y + y][idx_x + x];
			if (value == num)
			{
				return false;
			}
		}
	}
	return true;
}

bool recursive(vector<vector<int>>& board)
{
	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[0].size(); x++)
		{
			int value = board[y][x];
			if (0 == value)
			{
				for (int num = 1; num < 10; num++)
				{
					if (isValid(num, x, y, board))
					{
						board[y][x] = num;
						if (recursive(board))
						{
							return true;
						}
						board[y][x] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

vector<vector<int>> solution(vector<vector<int>>& board)
{
	recursive(board);

	return board;
}

void print(const vector<vector<int>>& board);

int main()
{
	vector<vector<int>> board =
	{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	vector<vector<int>> result = solution(board);
	print(result);
}

void print(const vector<vector<int>>& board)
{
	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[0].size(); x++)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
}

