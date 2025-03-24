#include <iostream>
#include <vector>

int main()
{
    std::vector<int> Vector1;
    std::vector<int> Vector2(10); // Vector[0] ~ Vector[9] 10개의 공간 생성, 데이터는 모두 0
    std::vector<int> Vector3(10, 1); // Vector[0] ~ Vector[9] 10개의 공간 생성, 데이터는 모두 1
    std::vector<int> Vector4{ 10, 20, 30, 40, 50 }; // Vector[0] = 10, Vector[1] = 20, Vector[3] = 30 ...
    std::vector<int> Vector5(Vector4); // Vector4 깊은 복사
    std::vector<int> Vector6(Vector4.begin(), Vector4.begin() + 3); // Vector4[0] ~ Vector4[2]까지 깊은 복사

    std::vector<std::vector<int>> Matrix1(2, std::vector<int>(3, 1)); // 2행 3열, 모든 초기값 1

    std::vector<std::vector<int>> Matrix2 {
        { 1, 2, 3 }, 
        { 4, 5, 6 }
    }; 


    std::cout << "Hello World!\n";
}
