#include<ctype.h>
#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");//�й� �Է�
	char lettering[100]; //���ڿ� �޴� �迭
	int big_num=0, small_num=0;// ��ҹ��ڰ� ����� ǥ���� ����
	
	printf("���ڿ��� �Է��ϼ���:");
	gets_s(lettering, 100);//gets_s�Լ��� ���ڿ� ����

	for (int a = 0; a<strlen(lettering); a++) {//������ ���� ���ڿ��� �ִ� ���ڸ� ��ҹ��ڷ� ����
		if (isupper(lettering[a])) {
			big_num++;
		}
		if (islower(lettering[a])) {
			small_num++;
		}
	}

	printf("'%s'�� ���ڱ���: %d\n", lettering, strlen(lettering));//������� ������
	printf("�빮���� ����: %d\n", big_num);
	printf("�ҹ����� ����: %d\n", small_num);

	return 0;
}