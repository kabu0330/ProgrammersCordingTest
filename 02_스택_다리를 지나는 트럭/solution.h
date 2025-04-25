#pragma once
#include <string>
#include <vector>
#include <queue>
using namespace std;

// bridge_length �ٸ����� Ʈ���� �ӹ��� �ð�
// weight �ٸ��� �ߵ� �� �ִ� ����
// truck_weights �� Ʈ�� ����
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
		++Time; // 1�� ����

		// ������ 1�ʸ��� �긴�� ť �ϳ� �����.
		CurWeight -= Bridge.front();
		Bridge.pop(); 

		int WaitingTruck = truck_weights[Index];

		if (WaitingTruck + CurWeight <= weight)
		{
			CurWeight += WaitingTruck;
			Bridge.push(WaitingTruck);

			++Index; // ���� Ʈ�� ���Կ� ��
			if (truck_weights.size() - 1 == Index)
			{
				--Index;
			}
		}
		else
		{
			Bridge.push(0);
		}

		if (true == Bridge.empty()) // �ٸ��� ��� �������� ����ð� ����
		{
			return Time;
		}
		
	}

	return 0;
}