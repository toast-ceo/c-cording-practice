#include <stdio.h>
#pragma warning(disable:4996)

void selection(int arr[]) { // �������� �Լ�
	
	int temp;// ���� �ӽ÷� �޾��ִ� ����

	for (int a = 0; a < 4; a++) { //�������� ���� �ϴ� �˰���
		for (int b = a+1; b < 5; b++) {
			if (arr[a] < arr[b]) {
				temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}
		}
	}
	for (int a = 0; a < 5; a++) {
		printf(" %d", arr[a]); //  �������� ���� ��� 
	}

}


int main() {
	printf("�й�: 202004026 �̸�: �̻�\n");// �й�, �̸�

	int num[5];// ������ �޴� �迭

	printf("���� 5���� �Է��Ͻÿ�\n");// ���� �Է�
	for (int a = 0; a < 5; a++) {
		scanf("%d", &num[a]);
	}

	printf("===���� �� �Է¹޴� ��===\n");// �������� �� �Է¹��� �� printf���� ��
	for (int a = 0; a < 5; a++) {
		printf(" %d", num[a]);
	}
	printf("\n");//���� ��� �� ���� ǥ��

	printf("===���� ���� ���� ���===\n");
	selection(num);//�������� ������ ���� �Լ�, �迭 �Ѱ��ֱ�
	
	return 0;
}