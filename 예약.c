#include <stdio.h>
#pragma warning(disable:4996)
int seat[10] = {0};

void reservation() {//���� ���� �Լ�
	int num1, num2;//���� �� ��ȣ

	for (int i = 0; i < 10; i++)//����� �¼� printf ǥ�� 
	{
		printf(" %d", seat[i]);
	}
	printf("\n");

	printf("�¼� ��ȣ�� 2���� �Է��Ͽ��ּ���:");// �����ȣ �Է�
	scanf("%d %d", &num1, &num2);
	
	//���� ��� 3���� : 1. �̸� ���� 2. ���� �¼��� ���� ��� 3. ���󿹾� 
	
	if (seat[num1-1] == 1 || seat[num2-1] == 1) {// 1. �̸� ����
		printf("�̹� ����� �ڸ��Դϴ�.\n");
	}

	else if (num1==num2) {//2. ���� �¼��� ���� ���
		printf("������ �ڸ��� ���ڸ� �Դϴ�.\n");
	}

	else if (seat[num1-1] == 0 && seat[num2-1] == 0) {//3. ���� ����
		seat[num1-1] = 1;
		seat[num2-1] = 1;
		printf("����Ǿ����ϴ�.\n");
	}

	
}

int main() {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");
	char answer;//���� ���θ� �Է� �޴� ����

	do{
		
		printf("�¼��� �����Ͻðڽ��ϱ�?(y �Ǵ�n)");//���� ���� �Է�
		scanf(" %c", &answer); 
	

	if (answer == 'y')
	{
		printf("-------------------------------\n");// ���� ��
		printf(" 1 2 3 4 5 6 7 8 9 10\n");
		printf("-------------------------------\n");
		reservation();
	}
	else if (answer == 'n') {// 'n' �Է½� ����
		break;}
	} while (1);
	
	return 0;
}