#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

struct book { //BOOK ����ü ����
	char book_name[20]; // �̸� ����
	char writer[10];// �۰�
	int price; // ����
	char genre[10]; //�帣
};
int main(void) {

	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");

	int num; // �帣 ���� �޴� ����
	struct book booklist[3];//booklist������ 3�� �ޱ����� �迭�� ����

	for (int a = 0; a < 3; a++) {// 3�� �޴� �ݺ���

		printf("å �̸�:");//å�̸��� ����
		gets_s(booklist[a].book_name,20);
	

		printf("�۰� �̸�:"); //�۰� �̸��� ����
		gets_s(booklist[a].writer, 10);
		

		printf("�帣 : 1. �Ҽ� 2. ������ 3. ����\n");// �帣�� ��ȣ �Է¿� ���� ���� �� �ְ���
		scanf(" %d", &num);
	

		switch (num)//���� 1, 2, 3�� ����� �� ����
		{
		case 1:
			strcpy(booklist[a].genre, "�Ҽ�");
			break;
		case 2:
			strcpy(booklist[a].genre, "������");
			break;
		case 3:
			strcpy(booklist[a].genre, "����");
			break;
		}

		printf("����:");//������ ����
		scanf(" %d", &booklist[a].price);
		getchar();
	}

	printf("=======���======\n");
	for (int a = 0; a < 3;a++) {//��� �� ���
		printf("å �̸�:%s\n", booklist[a].book_name);
		printf("�۰� �̸�:%s\n", booklist[a].writer);
		printf("�帣:%s\n", booklist[a].genre);
		printf("����:%d\n", booklist[a].price);

	};
	return 0;
}




