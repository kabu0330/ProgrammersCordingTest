#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cols;
int solution_count = 0;

bool is_safe(int row, int col)
{
	for (int prev_row = 1; prev_row < row; ++prev_row)
	{
		if (cols[prev_row] == col)
		{
			return false;
		}
		if (abs(row - prev_row) == abs(col - cols[prev_row]))
		{
			return false;
		}
	}
	return true;
}

void solve(int row)
{
	if (row > n)
	{
		++solution_count;
		return;
	}
	for (int col = 1; col <= n; col++)
	{
		if (is_safe(row, col))
		{
			cols[row] = col;
			solve(row + 1);
		}
	}
}

int main()
{
	cin >> n;
	cols.resize(n + 1);

	solve(1);
	cout << solution_count;
}

