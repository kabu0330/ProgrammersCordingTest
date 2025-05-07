#include <iostream>
#include <string>
#include <vector>

using namespace std;

int DFS(const std::vector<int>& _Numbers, int _Index, int _Sum, int _Target)
{
	if (_Index == _Numbers.size())
	{
		return _Sum == _Target ? 1 : 0;
	}
	
	int Count = 0;
	Count += DFS(_Numbers, _Index + 1, _Sum + _Numbers[_Index], _Target);
	Count += DFS(_Numbers, _Index + 1, _Sum - _Numbers[_Index], _Target);

	return Count;
}

int solution(vector<int> numbers, int target) 
{
    return DFS(numbers, 0, 0, target);
}

int main()
{
    std::cout << solution({ 1, 1, 1, 1 }, 3);
}
