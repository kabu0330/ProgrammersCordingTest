
#include "another.h"

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
	unordered_set<string> string;
	for (int i = 0; i < string_list.size(); i++)
	{
		string.insert(string_list[i]);
	}
	
	vector<bool> answer;
	for (int i = 0; i < query_list.size(); i++)
	{
		if (string.end() != string.find(query_list[i]))
		{
			answer.push_back(true);
		}
		else
		{
			answer.push_back(false);
		}
	}

	return answer;
}



int main()
{
	vector<string> string_list = { "apple", "banana", "cherry" };
	vector<string> query_list = { "banana", "kiwi", "melon", "apple" };
	vector<bool> result = solution(string_list, query_list);
	vector<bool> result2 = solution2(string_list, query_list);
}

