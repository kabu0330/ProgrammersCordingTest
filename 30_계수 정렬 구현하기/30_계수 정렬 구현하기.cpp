
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s)
{
	vector<int> counts(26, 0);
	
	for (char c : s)
	{
		counts[c - 'a']++;
	}

	string sorted_str = "";
	for (int i = 0; i < 26; i++)
	{
		//				해당 문자의 개수만큼 문자 추가
		sorted_str += string(counts[i], i + 'a');
	}
	return sorted_str;
}

int main()
{
	cout << solution("hello");
	
}

