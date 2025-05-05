#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) 
{
    std::unordered_set<std::string> Hash(phone_book.begin(), phone_book.end());

    for (const std::string& Number : Hash)
    {
        std::string PreFix;
        for (int i = 0; i < Number.length() - 1; i++)
        {
            PreFix += Number[i];
            if (Hash.end() != Hash.find(PreFix))
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    std::cout << solution({ "123", "456", "789" });
}
