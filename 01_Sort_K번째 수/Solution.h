#pragma once

#include <string>
#include <vector>

using namespace std;

std::vector<int> Sort(std::vector<int> _SortVector);
std::vector<int> Merge(std::vector<int> _Left, std::vector<int> _Right);

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
	for (size_t CommandsCount = 0; CommandsCount < commands.size(); CommandsCount++)
	{
		std::vector<int> UnsortVector;

		int i = commands[CommandsCount][0] - 1;
		int j = commands[CommandsCount][1] - 1;
		int k = commands[CommandsCount][2] - 1;
		for (i; i <= j; i++)
		{
			int Vaule = array[i];
			UnsortVector.push_back(Vaule);
		}
		std::vector<int> SortVector = Sort(UnsortVector);
		answer.push_back(SortVector[k]);
	}

    return answer;
}

std::vector<int> Sort(std::vector<int> _SortVector)
{
	if (_SortVector.size() <= 1)
	{
		return _SortVector;
	}

	int Mid = _SortVector.size() / 2;

	std::vector<int> Left(_SortVector.begin(), _SortVector.begin() + Mid);
	std::vector<int> Right(_SortVector.begin() + Mid, _SortVector.end());

	return Merge(Sort(Left), Sort(Right));
}

std::vector<int> Merge(std::vector<int> _Left, std::vector<int> _Right)
{
	std::vector<int> Result;
	
	int i = 0;
	int j = 0;

	while (i < _Left.size() && j < _Right.size())
	{
		if (_Left[i] < _Right[j])
		{
			Result.push_back(_Left[i]);
			++i;
		}
		else
		{
			Result.push_back(_Right[j]);
			++j;
		}
	}

	while (i < _Left.size())
	{
		Result.push_back(_Left[i]);
		++i;
	}
	while (j < _Right.size())
	{
		Result.push_back(_Right[j]); 
		++j;
	}

	return Result;
}