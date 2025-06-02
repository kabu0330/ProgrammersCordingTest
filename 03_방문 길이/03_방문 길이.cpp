
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "another.h"

using namespace std;
int solution(std::string _str)
{
    bool Visited[11][11][4] = { false };
    enum EDir
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    struct FPoint
    {
        int x = 5;
        int y = 5;
    };
    FPoint Pos({ 5, 5 });
    FPoint PrevPos = Pos;

    int Dir = -1;
    int ReverseDir = -1;
    int answer = 0; 
    for (size_t i = 0; i < _str.length(); i++)
    {
        char dir = _str[i];
        if (dir == 'U')
        {
            if (PrevPos.y == 10)
            {
                continue;
            }
            
            Pos.y++;
            Dir = EDir::UP;
            ReverseDir = EDir::DOWN;    
        }
        else if (dir == 'D')
        {
            if (PrevPos.y == 0)
            {
                continue;
            }
            Pos.y--;
            Dir = EDir::DOWN;
            ReverseDir = EDir::UP;
        }
        else if (dir == 'L')
        {
			if (PrevPos.x == 0)
			{
                continue;
			}
            Pos.x--;
            Dir = EDir::LEFT;
            ReverseDir = EDir::RIGHT;
   
        }
        else if (dir == 'R')
        {
            if (PrevPos.x == 10)
            {
                continue;   
            }
            Pos.x++;
            Dir = EDir::RIGHT;
            ReverseDir = EDir::LEFT;
        }
        
        if (false == Visited[PrevPos.y][PrevPos.x][Dir])
        {
            answer++;

            Visited[PrevPos.y][PrevPos.x][Dir] = true;
            Visited[Pos.y][Pos.x][ReverseDir] = true;
        }
        PrevPos = Pos;
    }
      
    return answer;
}

int main()
{
    std::string str = "ULURRDLLU";
    std::string str1 = "LULLLLLLU";
    int result0 = solution(str);
    int result1 = solution(str1);

    int result2 = another_solution(str);
    int result3 = another_solution(str1);
}

