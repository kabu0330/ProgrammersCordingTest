
#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::vector<int> vec(3, 0);
	std::stack<int> st(vec.begin(), vec.end());
	int a = st.top();
}

