#include <stdio.h>
#pragma warning(disable:4996)

void selection(int arr[]) { // 내림차순 함수
	
	int temp;// 값을 임시로 받아주는 변수

	for (int a = 0; a < 4; a++) { //내림차순 정렬 하는 알고리즘
		for (int b = a+1; b < 5; b++) {
			if (arr[a] < arr[b]) {
				temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}
		}
	}
	for (int a = 0; a < 5; a++) {
		printf(" %d", arr[a]); //  내림차순 정렬 결과 
	}

}


int main() {
	printf("학번: 202004026 이름: 이삭\n");// 학번, 이름

	int num[5];// 정수를 받는 배열

	printf("정수 5개를 입력하시오\n");// 정수 입력
	for (int a = 0; a < 5; a++) {
		scanf("%d", &num[a]);
	}

	printf("===정렬 전 입력받는 값===\n");// 내림차순 전 입력받은 값 printf해준 것
	for (int a = 0; a < 5; a++) {
		printf(" %d", num[a]);
	}
	printf("\n");//정수 출력 후 엔터 표시

	printf("===내림 차순 정렬 결과===\n");
	selection(num);//내림차순 정렬을 위한 함수, 배열 넘겨주기
	
	return 0;
}