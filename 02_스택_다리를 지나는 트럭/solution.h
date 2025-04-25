#pragma once
#include <string>
#include <vector>
#include <queue>
using namespace std;

// bridge_length 다리에서 트럭이 머무는 시간
// weight 다리가 견딜 수 있는 무게
// truck_weights 각 트럭 무게
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	std::queue<int> Bridge;
	for (int i = 0; i < bridge_length; i++)
	{
		Bridge.push(0);
	}

	int Time = 0;
	int CurWeight = 0;
	int Index = 0;
	while (true)
	{
		++Time; // 1초 증가

		// 무조건 1초마다 브릿지 큐 하나 지운다.
		CurWeight -= Bridge.front();
		Bridge.pop(); 

		int WaitingTruck = truck_weights[Index];

		if (WaitingTruck + CurWeight <= weight)
		{
			CurWeight += WaitingTruck;
			Bridge.push(WaitingTruck);

			++Index; // 다음 트럭 무게와 비교
			if (truck_weights.size() - 1 == Index)
			{
				--Index;
			}
		}
		else
		{
			Bridge.push(0);
		}

		if (true == Bridge.empty()) // 다리를 모두 지났으면 경과시간 리턴
		{
			return Time;
		}
		
	}

	return 0;
}