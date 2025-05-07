#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
    //return DFS(numbers, 0, 0, target);
	struct State
	{
		int Index = 0;
		int Sum = 0;
	};
	
	std::queue<State> Queue;
	Queue.push({ 0, 0 });

	int Count = 0;

	while (false == Queue.empty())
	{
		State CurState = Queue.front();
		Queue.pop();

		if (CurState.Index == numbers.size())
		{
			if (CurState.Sum == target)
			{
				++Count;
				continue;
			}
		}

		Queue.push({ CurState.Index + 1, CurState.Sum + numbers[CurState.Index] });
		Queue.push({ CurState.Index + 1, CurState.Sum - numbers[CurState.Index] });
	}
	return Count;
}

int main()
{
    std::cout << solution({ 1, 1, 1, 1, 1 }, 3);
}
