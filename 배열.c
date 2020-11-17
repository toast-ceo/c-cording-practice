#include<stdio.h>
#pragma warning (disable:4996)
#define product 2 // 2의 상수를 product 변수로 정의


void input_matrix(char name, int matrix[product][product]); // 입력받는 함수
void print_matrix(int matrix[product][product]); //입력받은 값을 출력하는 함수
void plus_matrix(int matrix_1[product][product], int matrix_2[product][product]); // 입력받은 값을 더한 후 출력하는 값

int main() {
	int A[product][product] = { 0 }, B[product][product] = { 0 }; // 4개의 값을 받을 수 있는 2차원 배열 A, B를 정의
	printf("학번:202004026 이름: 이삭\n");

	input_matrix(65,A);// A배열에 입력을 받음.
	printf("\n");

	input_matrix(66,B);// B배열에 입력을 받음.
	printf("\n");

	print_matrix(A);//A배열에 입력을 받은 값을 출력.
	printf("\n+ \n");
	print_matrix(B);//B배열에 입력을 받은 값을 출력.

	printf("\n=\n---------------\n");
	plus_matrix(A, B);//A와 B배열의 값을 각각 더하고 출력하는 함수.
}

void input_matrix(char name, int matrix[product][product]) {//배열에 값을 입력받게하는 함수
	for (int i = 0; i < 2; i++) {//이중 for문을 통해 2차원 배열에 값
		for (int w = 0; w < 2; w++) {
			printf("%c 행렬의 (%d,%d):", name, i, w);
			scanf("%d", &matrix[i][w]);
		}
	}
}

void print_matrix(int matrix[product][product]) {//배열에 값을 출력하는 함수
	for (int i = 0; i < 2; i++) {//이중 for문을 통해 2차원 배열을 활용하여 print을 이용하여 출력
		for (int w = 0; w < 2; w++) {
			printf("  %d", matrix[i][w]);
		}
		printf("\n");//행을 바꾸기 위한 엔터
	}
}

void plus_matrix(int matrix_1[product][product], int matrix_2[product][product]) {//배열에 값을 더하고 출력하는 함수
	for (int i = 0; i < 2; i++) {//이중 for문을 통해 2차원 배열을 활용하여 더한 값을 print을 이용하여 출력
		for (int w = 0; w < 2; w++) {
			printf("  %d", matrix_1[i][w]+matrix_2[i][w]);
		}
		printf("\n");//행을 바꾸기 위한 엔터
	}
}



