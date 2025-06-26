
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k)
{
	int answer;
	queue<int> queue;
	
	for (int i = 1; i < n + 1; i++)
	{
		queue.push(i);
	}

	while (false == queue.empty())
	{
		for (int i = 1; i < k; i++)
		{
			int front = queue.front();
			queue.pop();
			queue.push(front);
		}
		
		answer = queue.front();
		queue.pop();
	}

	return answer;
}

int main()
{
	int n = 5, k = 2;
	int result = solution(n, k);
}
