#include <iostream>
#include <vector>

int main()
{
	int N = 0, M = 0;
	std::cin >> N >> M;

	std::vector<std::vector<std::vector<int>>> Matrix(2, std::vector<std::vector<int>>(N, std::vector<int>(M, 0)));
	
	for (size_t i = 0; i < Matrix.size(); i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::vector<int> Input(M, 0);
			for (int k = 0; k < M; k++)
			{
				int Value = 0;
				std::cin >> Value;
				Input[k] = Value;
			}
			Matrix[i][j] = Input;
		}	
	}

	std::vector<std::vector<int>> Result(N, std::vector<int>(M, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			Result[y][x] = Matrix[0][y][x] + Matrix[1][y][x];
		}
	}

	for (size_t y = 0; y < Result.size(); y++)
	{
		for (size_t x = 0; x < Result[0].size(); x++)
		{
			std::cout << Result[y][x] << " ";
		}
		std::cout << std::endl;
	}
}

