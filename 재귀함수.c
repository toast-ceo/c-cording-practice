#include <stdio.h>
#pragma warning(disable: 4996)

int power(int base, int power_raised) {// ����Լ�
	if (power_raised <= 1) {
		return base; //������ ���� 1�� ��� base ������ ������ ����� ��.
	}
	else { //1�� �ƴҰ�� ����Լ��� ����
		return (base * power (base, power_raised - 1));
	}
	
}

int main(void) {
	printf("�й�:202004026 �̸�: �̻�\n");
	int num, index; //  �ؼ� , ���� ����
	printf("�ؼ� : "); scanf("%d", &num); // �ؼ� �Է�
	printf("���� : "); scanf("%d", &index); //���� �Է�

	int p = power(num, index);// �Լ��� ���� ����� ����
	printf("%d^%d=%d", num, index,p); // ���� ���

	return 0;
}
