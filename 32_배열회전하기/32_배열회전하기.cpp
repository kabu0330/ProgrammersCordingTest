
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate_90(const vector<vector<int>>& arr)
{
	int n = arr.size();
	vector<vector<int>> rotated_arr(n, vector<int>(n, 0));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			// rotated_arr[0][3] = arr[0][0]
			// rotated_arr[0][2] = arr[0][1]
			// rotated_arr[0][1] = arr[0][2]
			// rotated_arr[0][0] = arr[0][3]
			rotated_arr[x][n - y - 1] = arr[y][x];
		}
	}
	return rotated_arr;
}

vector<vector<int>> solution(vector<vector<int>> arr, int n)
{
	vector<vector<int>> rotated_arr = arr;
	for (int i = 0; i < n; i++)
	{
		rotated_arr = rotate_90(rotated_arr);
	}
	return rotated_arr;
}

int main()
{
	vector<vector<int>> arr = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	solution(arr, 2);

}

