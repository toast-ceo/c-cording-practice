#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {

	printf("학번:202004026 이름: 이삭\n");//학번,이름
	int score[6];// 배열을 활용한 학생 점수
	score[0] =  0;

	for (int i = 1; i < 6; i++) { // for문을 활용한 입력
		printf("%d번 학생 점수 : ", i);
		scanf("%d", &score[i]);
	}

	int temp;// *이 찍히는 횟수를 위한 변수
	printf("======입력 결과=====\n");

	for (int i = 1; i < 6; i++) {// for문을 활용한 출력
	
		temp = score[i]/10;
		printf("%d번 학생 점수 : %d  (", i, score[i]);
		
		if (temp > 0) {// temp 값에 따른 별 찍기 or - 찍기
			for (int j = 0; j<temp; j++) {
				printf("*");
			}
			printf(")\n");
		}
		else {
			printf("-)\n");
		}

	}
	
	int plus=0;// 총합& 평균을 구하기 위한 변수

	for (int i = 1; i < 6; i++) {
		plus += score[i];
	}
	printf("총점 : %d\n",plus);
	printf("평균 : %.2f", (double)plus / 5);// 형변환 이용

	return 0;
}