
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer;

    int choice = nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    answer = min(choice, (int)nums.size());

    return answer;
}

int main()
{
    vector<int> nums = { 3, 3, 3, 2, 2, 4 };
    int result = solution(nums);
}

