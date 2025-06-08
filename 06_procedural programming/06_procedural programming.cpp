#include <iostream>
#include <Windows.h>

// 절차지향으로 자율주행(어댑티브 크루즈 컨트롤) 기능을 구현한다면
// 프로시저(함수)들을 가지고 레고 조립하듯이 적절하게 배치하고 재사용
/*
*  한계
*  1. 프로그램의 규모가 커지면 코드 흐름이 복잡해지고 프로시저가 대폭 늘어난다.
*  2. 프로시저의 다층 구조를 표현할 방법이 없다. 별도의 문서를 제작 배포해야 한다.
*  3. 다른 프로젝트 담당자가 접근하지 말아야 할 프로시저에 접근할 수 있다.
*/

int user_target_speed;
int acceleratiojn_adjusting_period;

void acceleration_output();
void pushing_break();
int inquireing_current_speed();
int inquiring_range();
int calculating_fit_speed(int range, int original_target_speed);
void acceleration_adjusting(int target_speed, int current_speed);

int main()
{
	bool do_cruise;
	int range, current_speed;

	while (do_cruise)
	{
		range = inquiring_range();
		current_speed = inquireing_current_speed();
		acceleration_adjusting(calculating_fit_speed(range, user_target_speed), current_speed);
		
		Sleep(acceleratiojn_adjusting_period);
	}
}

void acceleration_adjusting(int target_speed, int current_speed)
{
	if (target_speed == current_speed)
	{
		return;
	}
	if (target_speed > current_speed)
	{
		acceleration_output();
		return;
	}
	pushing_break();
}

void acceleration_output()
{
}

void pushing_break()
{
}

int inquireing_current_speed()
{
	return 0;
}

int inquiring_range()
{
	return 0;
}

int calculating_fit_speed(int range, int original_target_speed)
{
	return 0;
}