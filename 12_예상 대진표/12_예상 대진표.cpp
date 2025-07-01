
#include <iostream>


using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    // a가 b와 만나는지 아는 법
    // a가 홀수면 b가 a + 1인지?
    // a가 짝수면 b가 a - 1인지?
    // 둘 다 아니면 a,b 모두 2로 나누고 올림
    while (true)
    {
        if (0 == a % 2 && b == a - 1)
        {
            return answer;
        }
        else if (1 == a % 2 && b == a + 1)
        {
            return answer;
        }
        
        a = ceil((float)a / 2);
        b = ceil((float)b / 2);
        answer++;
    }

    return answer;
}

int main()
{
    int n = 8;
    int A = 4;
    int B = 7;
    int result = solution(n, A, B);
}

