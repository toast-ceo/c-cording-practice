#include <stdio.h>
#pragma warning(disable: 4996)

int power(int base, int power_raised) {// 재귀함수
	if (power_raised <= 1) {
		return base; //지수의 값이 1일 경우 base 값으로 리턴을 해줘야 함.
	}
	else { //1이 아닐경우 재귀함수를 돌림
		return (base * power (base, power_raised - 1));
	}
	
}

int main(void) {
	printf("학번:202004026 이름: 이삭\n");
	int num, index; //  밑수 , 지수 변수
	printf("밑수 : "); scanf("%d", &num); // 밑수 입력
	printf("지수 : "); scanf("%d", &index); //지수 입력

	int p = power(num, index);// 함수를 통해 결과값 도출
	printf("%d^%d=%d", num, index,p); // 최종 출력

	return 0;
}
