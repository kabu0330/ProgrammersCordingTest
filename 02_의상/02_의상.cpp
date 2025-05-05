#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// 의상 종류에서 하나만 입을 수 있다.
// (종류A + 안 입는다) * (종류B + 안 입는다) - 아무것도 안 입는다.
// (2 + 1 ) * (1 + 1) = 3 * 2 = 6 - 1 = 5가지 경우의 수
int solution(vector<vector<string>> clothes) {
    std::unordered_map<std::string, int> Hash;
	for (const std::vector<std::string>& Item : clothes)
	{
		const std::string& Type = Item[1];
		if (Hash.end() == Hash.find(Type))
		{
			Hash[Type] = 1;
		}
		else
		{
			++Hash[Type];
		}
	}

	int answer = 1;
	for (const pair<std::string, int>& Pair : Hash)
	{
		answer *= (Pair.second + 1);
	}
	return answer - 1;
}

int main()
{
	std::cout << solution({ { "yellow_hat", "headgear" }, { "blue_sunglasses", "eyewear" }, {"green_turban", "headgear"} });
}
