#pragma once
#include <vector>
#include <algorithm>

// 배열의 원소가 1개가 될 때 까지 분할하고, 병합할 때 정렬하여 병합하는 방법

void Merge(std::vector<int>& data, int left, int mid, int right);

//                                        0,      배열 크기 - 1
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
		// 하나의 원소를 가지고 있는 데이터
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

	// buff의 데이터를 원래 배열에 복사
	for (int x = left; x < right; x++)
	{
		data[x] = buff[x];
	}
}