
#include <iostream>
#include <vector>

using namespace std;
vector<int> cols;

bool is_safe(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int prev_col = cols[i];
		if (col == prev_col)
		{
			return false;
		}
		if (abs(row - i) == abs(col - prev_col))
		{
			return false;
		}
	}
	return true;
}

void solve(int row, int n, int& answer)
{
	if (row == n)
	{
		++answer;
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (is_safe(row, col))
		{
			cols[row] = col;
			solve(row + 1, n, answer);
		}
	}
}

long long solution(int n)
{
	int answer = 0;
	cols.resize(n);

	solve(0, n, answer);

	return answer;
}

int main()
{
	int n = 4;
	int result = solution(4);
	cout << result << endl;
}
