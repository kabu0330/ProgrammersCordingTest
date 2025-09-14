#include <iostream>
#include <vector>

using namespace std;



int main()
{
	
    vector<int> vec;
	for (int i = 1; i <= 10; i++)
	{
		size_t value = pow(28, i);
		vec.push_back(value);
		cout << value << endl;
	}
	int a = 0;
}
