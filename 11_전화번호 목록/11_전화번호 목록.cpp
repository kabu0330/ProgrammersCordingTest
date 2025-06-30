
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_set<string> hash(phone_book.begin(), phone_book.end());
    
    for (const string& str : phone_book)
    {
        string prev = "";
        for (int i = 0; i < str.length() - 1; i++)
        {
            prev += str[i];
            if (hash.end() != hash.find(prev))
            {
                return false;
            }
        }
    }
    return true;
}

bool solution2(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        string str = phone_book[i];
        string next = phone_book[i + 1];
        if (str == next.substr(0, str.size()))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << solution({ "123", "456", "789" }) << endl;
    std::cout << solution({ "119", "97674223", "1195524421" }) << endl;
    std::cout << solution2({ "123", "456", "789" }) << endl;
    std::cout << solution2({ "119", "97674223", "1195524421" });

}
