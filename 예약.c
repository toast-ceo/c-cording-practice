#include <stdio.h>
#pragma warning(disable:4996)
int seat[10] = {0};

void reservation() {//예약 관련 함수
	int num1, num2;//예약 할 번호

	for (int i = 0; i < 10; i++)//예약된 좌석 printf 표시 
	{
		printf(" %d", seat[i]);
	}
	printf("\n");

	printf("좌석 번호를 2개를 입력하여주세요:");// 예약번호 입력
	scanf("%d %d", &num1, &num2);
	
	//예약 경우 3가지 : 1. 미리 예약 2. 예약 좌석이 같을 경우 3. 정상예약 
	
	if (seat[num1-1] == 1 || seat[num2-1] == 1) {// 1. 미리 예약
		printf("이미 예약된 자리입니다.\n");
	}

	else if (num1==num2) {//2. 예약 좌석이 같은 경우
		printf("선택한 자리는 한자리 입니다.\n");
	}

	else if (seat[num1-1] == 0 && seat[num2-1] == 0) {//3. 정상 예약
		seat[num1-1] = 1;
		seat[num2-1] = 1;
		printf("예약되었습니다.\n");
	}

	
}

int main() {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");
	char answer;//예약 여부를 입력 받는 변수

	do{
		
		printf("좌석을 예약하시겠습니까?(y 또는n)");//예약 여부 입력
		scanf(" %c", &answer); 
	

	if (answer == 'y')
	{
		printf("-------------------------------\n");// 숫자 판
		printf(" 1 2 3 4 5 6 7 8 9 10\n");
		printf("-------------------------------\n");
		reservation();
	}
	else if (answer == 'n') {// 'n' 입력시 종료
		break;}
	} while (1);
	
	return 0;
}