#include <iostream>

int main()
{
    int Number = 0;
    std::cin >> Number;

    int Count = 0;
    while (Number > 0)
    {
        Number /= 10;
        ++Count;
    }
    
    

    int Result = 0;
    std::cout << Result;
}
