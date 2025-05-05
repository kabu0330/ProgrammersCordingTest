#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int NumSize = nums.size() / 2;
    std::sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size() > NumSize ? NumSize : nums.size();
}

int main()
{
    std::cout << solution({ 3, 1, 2 , 3 });

}

