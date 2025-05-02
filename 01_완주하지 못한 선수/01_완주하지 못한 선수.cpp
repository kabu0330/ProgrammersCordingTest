#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
	std::unordered_map<string, int> Count;
	for (const string& Name : completion)
	{
		++Count[Name];
	}

	for (const string& Name : participant)
	{
		if (0 == Count[Name])
		{
			return Name;
		}
		--Count[Name];
	}
}

int main()
{
    std::cout << solution({ "leo", "kiki", "eden", "leo"}, {"eden", "kiki", "leo"});
}

