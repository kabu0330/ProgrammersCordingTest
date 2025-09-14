#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> heap;
vector<int> nums;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	nums.resize(n);
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> nums[i];
	}

	int index = 0;
	while (index != nums.size())
	{
		int value = nums[index];
		if (value == 0)
		{
			if (false == heap.empty())
			{
				int num = heap.top();
				heap.pop();
				cout << num << "\n";
			}
			else
			{
				// 비어있다면
				cout << 0 << "\n";
			}
		}

		heap.push(value);
		++index;
	}
	
}
