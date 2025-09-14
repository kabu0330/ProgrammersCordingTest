
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = {};
vector<int> nums;
bool is_used[9] = { };

void solve(int idx, int start)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	int last_num = 0;
	for (int i = start; i < nums.size(); i++)
	{
		if (last_num != nums[i])
		{
			int value = nums[i];
			arr[idx] = value;
			last_num = value;
			solve(idx + 1, i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	nums.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	std::sort(nums.begin(), nums.end());

	solve(0, 0);
}

