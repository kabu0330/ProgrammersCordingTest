#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool IsConvertible(const std::string& A, const std::string& B)
{
	int Diff = 0;
	for (size_t i = 0; i < A.size(); i++)
	{
		if (A[i] != B[i])
		{
			++Diff;
		}
	}
	return Diff == 1; // 한 글자만 다르면 변환 가능
}

int solution(string begin, string target, vector<string> words) 
{
	if (std::find(words.begin(), words.end(), target) == words.end())
	{
		return 0;
	}

	std::queue<std::pair<std::string, int>> Queue;
	Queue.push({ begin, 0 });

	std::vector<bool> Visited(words.size(), false);

	while (false == Queue.empty())
	{
		std::string Current = Queue.front().first;
		int Count = Queue.front().second;
		Queue.pop();

		if (Current == target)
		{
			return Count;
		}

		for (size_t i = 0; i < words.size(); i++)
		{
			if (false == Visited[i] && true == IsConvertible(Current, words[i]))
			{
				Visited[i] = true;
				Queue.push({ words[i], Count + 1 });
			}
		}
		
	}

    return 0;
}

int main()
{
    std::cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}

