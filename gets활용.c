#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");

	char name[100];//�̸� �޴� ����
	int name_num=0;//�й��� �޴� ����
	char want_tell[100];//�ϰ� ���� ���� �޴� ����

	printf("�̸��� �Է��ϼ���:");
	gets_s(name, 100);//gets_s�Լ��� �̸��� ����
	printf("�й��� �Է��ϼ���:");
	scanf("%d", &name_num);//scanf�Լ��� �й��� ����
	getchar();//���� �ʱ�ȭ
	printf("�ϰ���� ���� ���ּ���.\n");
	gets_s(want_tell, 100);//gets_s�Լ��� �ϰ� ���� ���� ����

	printf("\n======��� ���=======\n");//����� ���
	printf("�̸�:%s\n",name);
	printf("�й�:%d\n",name_num);
	printf("�ϰ���� ���� ���ּ���.\n%s",want_tell);

	return 0;
}