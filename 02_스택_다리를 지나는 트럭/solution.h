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
	int Index = 0;
	int BridgeWeight = 0;
	while (true != Bridge.empty())
	{
		++Time;

		int CurTruck = Bridge.front();
		Bridge.pop();

		BridgeWeight -= CurTruck;

		if (Index == truck_weights.size())
		{
			continue;
		}

		int NextTruckWeight = truck_weights[Index];
		if (BridgeWeight + NextTruckWeight <= weight)
		{
			Bridge.push(NextTruckWeight);
			++Index;
			BridgeWeight += NextTruckWeight;
		}
		else
		{
			Bridge.push(0);
		}
	}

	return Time;
}