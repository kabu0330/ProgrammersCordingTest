
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<int> arr, int target)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (target == arr[i] + arr[j])
			{
				return true;
			}
		}
	}
	return false;
}

bool solution2(vector<int> arr, int target)
{
	unordered_map<int, int> hash;
	for (int i = 0; i < arr.size(); i++)
	{
		hash.insert({ arr[i], 1 });
	}
	
	for (int i = 0; i < arr.size(); i++)
	{
		int targetValue = target - arr[i];
		if (hash.end() != hash.find(targetValue))
		{
			return true;
		} 
	}
	return false;
}

int main()
{
	vector<int> arr = { 1, 2, 3, 4, 8 };
	int target = 6;
	bool result = solution(arr, target);
	bool result2 = solution2(arr, target);

}

