#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {

	printf("�й�:202004026 �̸�: �̻�\n");//�й�,�̸�
	int score[6];// �迭�� Ȱ���� �л� ����
	score[0] =  0;

	for (int i = 1; i < 6; i++) { // for���� Ȱ���� �Է�
		printf("%d�� �л� ���� : ", i);
		scanf("%d", &score[i]);
	}

	int temp;// *�� ������ Ƚ���� ���� ����
	printf("======�Է� ���=====\n");

	for (int i = 1; i < 6; i++) {// for���� Ȱ���� ���
	
		temp = score[i]/10;
		printf("%d�� �л� ���� : %d  (", i, score[i]);
		
		if (temp > 0) {// temp ���� ���� �� ��� or - ���
			for (int j = 0; j<temp; j++) {
				printf("*");
			}
			printf(")\n");
		}
		else {
			printf("-)\n");
		}

	}
	
	int plus=0;// ����& ����� ���ϱ� ���� ����

	for (int i = 1; i < 6; i++) {
		plus += score[i];
	}
	printf("���� : %d\n",plus);
	printf("��� : %.2f", (double)plus / 5);// ����ȯ �̿�

	return 0;
}