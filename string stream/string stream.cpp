
#include <iostream>
#include <sstream>

// 단순 문자열 파싱을 할 때는 stringstream이 공백 분리를 해줘서 편리하다.

using namespace std;

int main()
{
    std::string str = "absd u1234 5566";
    std::stringstream sstream(str);
    


    std::string text0, text1, text2, text3;
    sstream >> text0;
    sstream >> text1;
    sstream >> text2;
    sstream >> text3;

    std::cout << text0 << std::endl;
    std::cout << text1 << std::endl;
    std::cout << text2 << std::endl;
    std::cout << text3 << std::endl;

    sstream.clear();
    sstream.seekp(0, std::ios::end);
    sstream << "Hello World!";
    std::string text = sstream.str();


    sstream.clear();
    sstream.str("");
    sstream << "Hello World!";
    std::string text11 = sstream.str();
    sstream << "추가 추가 추가";
    std::string text12 = sstream.str();

}
