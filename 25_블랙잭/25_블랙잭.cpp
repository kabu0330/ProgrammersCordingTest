#include <iostream>
#include <vector>

using namespace std;

/* 1. 합이 21을 초과하지 않는 가장 큰 값을 구하는 게임
*  2. 숫자 3개를 골라 M을 넘지 않으면서 가장 가까운 수
*/

int n, m;
vector<int> cards;
vector<int> is_used;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cards.resize(n);
	is_used.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	int best = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int card_sum = cards[i] + cards[j] + cards[k];
				if (card_sum <= m && card_sum > best)
				{
					best = card_sum;
					if (best == m)
					{
						break;
					}
				}
			}
		}
	}
	cout << best;
}

