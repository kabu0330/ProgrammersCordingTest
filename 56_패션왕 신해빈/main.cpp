#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


#define endl '\n'

using namespace std;

// 전역 변수
int n;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--)
	{
		int cnt;
		cin >> cnt;

		// 옷의 이름은 중요하지 않다. 가짓수가 몇 개냐가 중요하다.
		unordered_map<string, int> cloths;
		while (cnt--)
		{
			string name, type;
			cin >> name >> type;

			++cloths[type];
		}

		long long totalCase = 1;

		// 옷 가짓수 + 1(입지 않는다)
		for (const auto& ele : cloths)
		{
			totalCase *= (ele.second + 1);
		}

		// 아무것도 입지 않는 경우의 수는 제외한다.
		cout << totalCase - 1 << endl;
	}

}

