#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> ret(arr1.size(), vector<int>(arr2[0].size(), 0));

	// (I x K) * (K x J) = I x J
	// (3 x 2) * (2 x 2) = 3 x 2

	for (int i = 0; i < arr1.size(); i++)
	{
		for (int j = 0; j < arr2[0].size(); j++)
		{
			for (int k = 0; k < arr2.size(); k++)
			{
				ret[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	
	for (auto& vec : ret)
	{
		for (auto& ele : vec)
		{
			cout << ele << " ";
		}
		cout << endl;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<vector<int>> arr1 = { {1,4}, {3,2 }, {4, 1} };
	vector<vector<int>> arr2 = { {3,3}, {3,3 } };

	vector<vector<int>> ret = solution(arr1, arr2);
}

