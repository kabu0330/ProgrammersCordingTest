
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	
	int count = 0;
	int number = 665;

	while (count < n)
	{
		++number;

		string str = to_string(number);

		if (str.find("666") != string::npos)
		{
			++count;
		}
	}

	cout << number;
}

