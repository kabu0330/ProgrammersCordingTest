
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = {};
vector<int> nums;
bool is_used[9] = {};

void solve(int idx)
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

	for (int i = 0; i < nums.size(); i++)
	{
		if (false == is_used[i])
		{
			arr[idx] = nums[i];
			is_used[i] = true;
			solve(idx + 1);
			is_used[i] = false;
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
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	solve(0);
}
