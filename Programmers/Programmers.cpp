#include <iostream>
#include <string>
#include <vector>
// 가로 w개, 총 n개, 상자번호 num, return 꺼내야 할 박스 개수

using namespace std;

int solution(int n, int w, int num) 
{
    if (num > n)
    {
        return 0;
    }

    // n = 22, w = 6
    std::vector<std::vector<int>> Boxes;
    int Index = 1;
    int Floor = static_cast<int>(n / w);
    Boxes.resize(Floor + 1); // y축
    for (int i = 0; i <= Floor; i++)
    {
        Boxes[i].resize(w); // x축
    }

    for (int y = 0; y <= Floor; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (Index > n)
            {
                break;
            }
            if (1 == y % 2) // 홀수 층
            {
                Boxes[y][w - x - 1] = Index;
            }
            else // 짝수 층
            {
                Boxes[y][x] = Index;
            }
            Index++;
        }
    }
    
    int KeyValue = 0;
    int answer = 0;
    for (int y = 0; y <= Floor; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (Boxes[y][x] == num)
            {
                int Height = Boxes.size();
                answer = Height - y;

                if (0 == Boxes[Height - 1][x])
                {
                    answer -= 1;
                }
                break;
            }
        }
    }

    return answer;
}


int main()
{
    int a = solution(22, 6, 3);

    cout << "Result : " << a << endl;
}
