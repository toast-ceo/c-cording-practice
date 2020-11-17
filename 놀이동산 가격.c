#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {

	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	int time, age; // 시간과 나이 변수 선언.
	
	printf("현재 시간과 나이를 입력하세요:"); // 시간과 나이 입력.
	scanf("%d %d", &time, &age);

	/* 1. 시간으로 먼저 분류 
	   2. 그리고 나이에 맞게 분류 후 값 출력*/
	if (time >= 9 && time < 17) // 9~17시일 경우.
	{ 
		if (age >= 3 && age <= 12 || age >= 65)//3~12살 또는 65세 이상일 경우
		{
			printf("요금은 25000 입니다.");
		}
		else //3~12살 또는 65세 이상이 아닐 경우
		{
			printf("요금은 34000 입니다.");
		}
	}
	
	else //9~17시가 아닌 경우, 나이는 상관없으니 분류 x
	{
		printf("요금은 10000 입니다.");
	}

	return 0;
}