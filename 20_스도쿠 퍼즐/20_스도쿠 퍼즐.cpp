
#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col, int num)
{
	for (int x = 0; x < 9; ++x)
	{
		if (board[row][x] == num)
		{
			return false;
		}
	}

	for (int y = 0; y < 9; ++y)
	{
		if (board[y][col] == num)
		{
			return false;
		}
	}

	int start_row = (row / 3) * 3;
	int start_col = (col / 3) * 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[start_row + i][start_col + j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool solve(vector<vector<int>>& board)
{
	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			if (board[row][col] == 0)
			{
				for (int num = 1; num <= 9; ++num)
				{
					if (isValid(board, row, col, num))
					{
						board[row][col] = num;
						if (solve(board))
						{
							return true;
						}

						board[row][col] = 0;
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
	/** 
	*  1. 스도쿠에서 0인 칸을 찾는다.
	*  2. 더 이상 빈칸이 없다면 스도쿠가 완성된 것이므로 종료
	*  3. 찾은 빈칸에 1부터 9까지 숫자를 하나씩 넣어본다.
	*  4. 넣은 숫자가 스도쿠 규칙에 맞는지 확인한다.
	*  4-1. 행에 중복되는 숫자가 없고
	*  4-2. 열에 중복되는 숫자가 없고
	*  4-3. 3x3에 중복되는 숫자가 없어야 한다.
	*  5. 실패 시 3단계로 돌아간다.
	*  6. 1부터 9까지 모든 숫자를 시도해도 해답을 찾지 못했다면 현재 칸이 잘못되었으므로 현재 칸을 0으로 만들고 이전 단계로 돌아간다.
	*/ 

	solve(board);
	return board;
	
}

void printBoard(const vector<vector<int>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

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
	printBoard(result);
}

