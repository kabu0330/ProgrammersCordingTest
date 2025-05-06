#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) 
{
	if (N == number)
	{
		return 1;
	}

	std::vector<std::set<int>> DP(9);
	int NN = 0;
	for (int i = 1; i <= 8; i++)
	{
		NN = NN * 10 + N;
		DP[i].insert(NN);

		for (int j = 1; j < i; j++)
		{
			for (int A : DP[j])
			{
				for (int B : DP[i - j])
				{
					DP[i].insert(A + B);
					DP[i].insert(A - B);
					DP[i].insert(A * B);
					if (0 != B)
					{
						DP[i].insert(A / B);
					}
				}
			}
		}

		if (true == DP[i].count(number))
		{
			return i;
		}
	}
	return -1;
}

int main()
{
    std::cout << solution(5, 12);
}
