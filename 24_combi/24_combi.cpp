

#include <iostream>
#include <string>
#include <map>

using namespace std;

void combination(string src, string dest, int depth)
{
	if (dest.size() == depth)
	{
		cout << dest << "\n";
		return;
	}

	for (int i = 0; i < src.size(); i++)
	{
		combination(src.substr(i + 1), dest + src[i], depth);
	}
}

int main()
{
	string str = "ABCDE";
	string dest = "";
	combination(str, dest, 3);
}
