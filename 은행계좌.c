#include<stdio.h>
#pragma warning(disable:4996)

int money; // ���������� �ܾ� ����, 0���� �ʱ�ȭ �Ǿ�����.

void save(int x) // ���� �Լ�
{
	money += x;
	printf("�� �ݾ� : %d ��\n", money);
}

void draw(int x) // ���� �Լ� 
{
	
	if (x < money) // �ܾװ� ���� �ݾ� �� �� ���.
	{
		money -= x;
		printf("�� �ݾ� : %d ��\n", money);
	}
	else
	{
		printf("�ܾ��� �����մϴ�.\n");
		printf("�� �ݾ� : %d��\n", money);
	}
}

void print() // �ܾ� Ȯ�� �Լ� 
{
	printf("�� �ݾ� : %d��\n", money);
}

int main()
{
	int menu_num, amount=0; // �޴� ����. �� ����  

	printf("�й� : 202004026 �̸�: �̻�\n");

	do // �޴��� �°� ���ǹ� ���� �� ���� ������ �������� ���� �ݺ��� ����. 
	{
		printf("�޴��� �����ϼ���\n 1. ���� 2. ���� 3. �ܾ�Ȯ�� 0. ���� :");
		scanf("%d",&menu_num);

		if (menu_num == 0) 
			break;

		else if (menu_num == 1) {
			printf("������ �ݾ��� �Է��ϼ��� : ");
			scanf("%d", &amount);
			save(amount);
		}
		else if (menu_num == 2) {
			printf("������ �ݾ��� �Է��ϼ��� : ");
			scanf("%d", &amount);
			draw(amount);
		}
		else if (menu_num == 3) {
			print();
		} 
		else
			printf("�߸��Է��ϼ̽��ϴ�.\n");

	} while (1);

	printf("����!");
}

