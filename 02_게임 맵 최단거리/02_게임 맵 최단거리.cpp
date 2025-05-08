
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
	int Height = maps.size();
	int Width = maps[0].size();

	std::vector<std::vector<int>> Distance(Height, std::vector<int>(Width, 0));
	
	std::queue<std::pair<int, int>> Queue;
	Queue.push({ 0, 0 });
	Distance[0][0] = 1;

	int DX[4] = { 0, 0, -1, 1 };
	int DY[4] = { -1, 1, 0, 0 };

	while (false == Queue.empty())
	{
		int X = Queue.front().second;
		int Y = Queue.front().first;
		Queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int NX = X + DX[i];
			int NY = Y + DY[i];
			
			if (0 <= NX && NX < Width && 0 <= NY && NY < Height)
			{
				if (1 == maps[NY][NX] && 0 == Distance[NY][NX])
				{
					Distance[NY][NX] = Distance[Y][X] + 1;
					Queue.push({ NY, NX });
				}
			}
		}
	}

	if (0 == Distance[Height - 1][Width - 1])
	{
		return -1;
	}

	return Distance[Height - 1][Width - 1];
}

int main()
{
    std::vector<std::vector<int>> maps =
	{
		{1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 0, 1}
	};

    std::cout << solution(maps);
}

