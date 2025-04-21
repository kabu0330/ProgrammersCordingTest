#pragma once
#include <vector>
#include <algorithm>

// �迭�� ���Ұ� 1���� �� �� ���� �����ϰ�, ������ �� �����Ͽ� �����ϴ� ���

void Merge(std::vector<int>& data, int left, int mid, int right);

//                                        0,      �迭 ũ�� - 1
void MergeSort(std::vector<int>& data, int left, int right)
{
	if (left < right) 
	{
		int mid = (left + right) / 2;
		MergeSort(data, left, mid);
		MergeSort(data, mid + 1, right);
		Merge(data, left, mid, right);
	}
	else
	{
		// �ϳ��� ���Ҹ� ������ �ִ� ������
	}
}

int buff[256] = {};
void Merge(std::vector<int>& data, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (data[i] <= data[j])
		{
			buff[k++] = data[i++];
		}
		else
		{
			buff[k++] = data[j++];
		}
	}

	while (i <= mid)
	{
		buff[k++] = data[i++];
	}

	while (j <= right)
	{
		buff[k++] = data[j++];
	}

	// buff�� �����͸� ���� �迭�� ����
	for (int x = left; x < right; x++)
	{
		data[x] = buff[x];
	}
}