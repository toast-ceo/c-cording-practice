#include<stdio.h>
#pragma warning (disable:4996)
#define product 2 // 2�� ����� product ������ ����


void input_matrix(char name, int matrix[product][product]); // �Է¹޴� �Լ�
void print_matrix(int matrix[product][product]); //�Է¹��� ���� ����ϴ� �Լ�
void plus_matrix(int matrix_1[product][product], int matrix_2[product][product]); // �Է¹��� ���� ���� �� ����ϴ� ��

int main() {
	int A[product][product] = { 0 }, B[product][product] = { 0 }; // 4���� ���� ���� �� �ִ� 2���� �迭 A, B�� ����
	printf("�й�:202004026 �̸�: �̻�\n");

	input_matrix(65,A);// A�迭�� �Է��� ����.
	printf("\n");

	input_matrix(66,B);// B�迭�� �Է��� ����.
	printf("\n");

	print_matrix(A);//A�迭�� �Է��� ���� ���� ���.
	printf("\n+ \n");
	print_matrix(B);//B�迭�� �Է��� ���� ���� ���.

	printf("\n=\n---------------\n");
	plus_matrix(A, B);//A�� B�迭�� ���� ���� ���ϰ� ����ϴ� �Լ�.
}

void input_matrix(char name, int matrix[product][product]) {//�迭�� ���� �Է¹ް��ϴ� �Լ�
	for (int i = 0; i < 2; i++) {//���� for���� ���� 2���� �迭�� ��
		for (int w = 0; w < 2; w++) {
			printf("%c ����� (%d,%d):", name, i, w);
			scanf("%d", &matrix[i][w]);
		}
	}
}

void print_matrix(int matrix[product][product]) {//�迭�� ���� ����ϴ� �Լ�
	for (int i = 0; i < 2; i++) {//���� for���� ���� 2���� �迭�� Ȱ���Ͽ� print�� �̿��Ͽ� ���
		for (int w = 0; w < 2; w++) {
			printf("  %d", matrix[i][w]);
		}
		printf("\n");//���� �ٲٱ� ���� ����
	}
}

void plus_matrix(int matrix_1[product][product], int matrix_2[product][product]) {//�迭�� ���� ���ϰ� ����ϴ� �Լ�
	for (int i = 0; i < 2; i++) {//���� for���� ���� 2���� �迭�� Ȱ���Ͽ� ���� ���� print�� �̿��Ͽ� ���
		for (int w = 0; w < 2; w++) {
			printf("  %d", matrix_1[i][w]+matrix_2[i][w]);
		}
		printf("\n");//���� �ٲٱ� ���� ����
	}
}



