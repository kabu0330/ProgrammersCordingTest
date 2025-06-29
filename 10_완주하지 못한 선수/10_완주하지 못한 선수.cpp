
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;


string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, int> names;
	
	for (const string& str : participant)
	{
		names[str]++;
	}

	for (string str : completion)
	{
		names[str]--;
		if (names[str] == 0)
		{
			names.erase(str);
		}
	}

	return names.begin()->first;
}

int main()
{
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };
	string result = solution(participant, completion);
}

