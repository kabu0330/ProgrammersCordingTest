#include <iostream>

int main()
{
    int func() noexcept;

    bool does_not_throw = noexcept(func());
    
    int a = 0;
}
