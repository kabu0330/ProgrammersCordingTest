#include <iostream>
#include <random>

int main()
{
	bool is_correct = false;
	int choice = 0;
	while (false == is_correct)
	{
		try {
			std::cout << "1 ~ 100 숫자를 입력해주세요. " << std::endl;
			std::cin >> choice;
			if (1 > choice || 100 < choice)
			{
				std::exception e("범위 내 값을 입력해주세요.");
				throw e;
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			std::cout << std::endl;
		}
	}
}
