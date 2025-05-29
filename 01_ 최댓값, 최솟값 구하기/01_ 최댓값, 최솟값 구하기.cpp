// 01_ 최댓값, 최솟값 구하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec = { 3, 1, 4, -5, 2 };
    
    std::vector<int>::iterator maxIter = std::max_element(vec.begin(), vec.end());



    std::vector<int>::iterator minIter = std::min_element(vec.begin(), vec.end());

    
}
