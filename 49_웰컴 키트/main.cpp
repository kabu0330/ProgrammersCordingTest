#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define endl '\n'

using namespace std;

// 전역 변수
int n, t, p;
int arr[6];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}

	cin >> t >> p;
	
	int tshirt = 0;
	int penBundle = 0;
	int pen = 0;

	for (int i = 0; i < 6; i++)
	{
		if (arr[i] == 0) continue;
		
		// 티셔츠
		int value =  arr[i] / t;
		if (arr[i] % t != 0) ++value;

		tshirt += value;
	}

	// 펜
	penBundle = n / p;
	n %= p;
	pen = n;

	cout << tshirt << endl;
	cout << penBundle << " " << pen;

}

