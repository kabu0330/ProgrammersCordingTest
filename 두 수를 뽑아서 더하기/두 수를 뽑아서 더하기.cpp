
#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>

std::vector<int> solution(const std::vector<int>& _vec)
{
	std::set<int> sum;
	for (size_t i = 0; i < _vec.size(); i++)
	{
		for (size_t j = i + 1; j < _vec.size(); j++)
		{			
			sum.insert(_vec[i] + _vec[j]);
		}
	}
	std::vector<int> answer(sum.begin(), sum.end());
	return answer;

}

int main()
{
	std::vector<int> numbers = { 2, 1, 3, 4, 1 };
	std::vector<int> result = solution(numbers);


}

