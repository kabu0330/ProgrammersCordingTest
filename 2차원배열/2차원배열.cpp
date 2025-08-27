#include <iostream>


int main()
{
    int arr[3][3] = {};

    // 9 6 3  -3씩
    // 8 5 2  -1씩

    int left = 9;
    int three = 3;

    for (int i = 0; i < 3; i++)
    {
        int right = 0;
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = left - (right * three);
            ++right;
        }
        --left;
    }
}

