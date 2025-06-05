#include <iostream>
#include <exception>    // set_terminate를 쓰려면 반드시 포함

// 예외 핸들러 함수
void MyTerminate()
{
    std::cout << "MyTerminate called" << std::endl;
    std::exit(-1);    // exit 대신 terminate 해도 된다
}

int main()
{
    // std 네임스페이스를 사용해서 terminate 핸들러 등록
    std::set_terminate(MyTerminate);

    // 이 예외를 잡아줄 catch가 없으므로
    // MyTerminate 함수가 호출돼야 한다
    throw 1;

    return 0;
}
