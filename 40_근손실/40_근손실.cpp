
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> weights;
vector<int> result;
bool visited[10] = {};

int sum = 0;

int dfs()
{
	int token = 0;

	if (result.size() == n)
	{
		return 1;
	}

	for (int i = 0; i < weights.size(); i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			result.push_back(weights[i]);

			sum += weights[i];
			sum -= k;

			if (sum >= 0)
			{
				token += dfs();
			}
			visited[i] = false;
			result.pop_back();

			sum -= weights[i];
			sum += k;
		}
	}

	return token;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	weights.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	cout << dfs();
	

}

