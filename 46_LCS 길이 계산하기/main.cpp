#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

int solution(string str1, string str2)
{
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			// 현재 비교하는 문자가 같으면
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[str1.size()][str2.size()];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int ret = solution("ABCBDAB", "BDCAB");
	cout << ret;
}

