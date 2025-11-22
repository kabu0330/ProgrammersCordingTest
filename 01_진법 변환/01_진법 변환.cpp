#include <iostream>
#include <string>
#include <cmath>

int main()
{
    std::string N = "";
    int B = 0;
    std::cin >> N >> B;
        
    long long Result = 0;
    for (size_t i = 0; i < N.length(); i++)
    {
        char Char = N[i];
        int Value = 0;
        if ('0' <= Char && '9' >= Char)
        {
            Value = Char - '0';
        }
        else if ('A' <= Char && 'Z' >= Char)
        {
            Value = Char - 'A' + 10;
        }

        int Digit = N.length() - i - 1; 
        long long Power = 1;
        for (int j = 0; j < Digit; j++)
        {
            Power *= B;
        }
        Result += static_cast<long long>(Value) * Power;
    }

    std::cout << Result << std::endl;
}
