
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8] = {};
vector<int> nums;

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

	int last_num = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int value = nums[i];
		if (last_num != value)
		{
			arr[idx] = value;
			last_num = value;
			solve(idx + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	nums.resize(n);
	for (int i = 0; i < nums.size(); i++)
	{
		cin >> nums[i];
	}

	std::sort(nums.begin(), nums.end());
	
	solve(0);
}
