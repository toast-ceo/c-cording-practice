#include <stdio.h>
#pragma warning(disable: 4996)

typedef struct student {
	int num;
	char name[20];
	double grade;
}STD;

STD get_max_stu(STD list[], int size);

int main(void) {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");

	STD list[3];
	int size = sizeof(list) / sizeof(list[0]);
	
	for (int a = 0; a < size; a++) {//����ü ���� �޴� ��
	
		printf("�̸�");
		scanf("%s", list[a].name);
		
		printf("�й�");
		scanf("%d", &list[a].num);
			
		printf("����");
		scanf("%lf", &list[a].grade);
		
		getchar();
	}
	STD max = get_max_stu(list, size);

	//���
	printf("������ ���� ���� �л��� (�̸�:%s, �й�: %d, ����: %lf)",max.name,max.num,max.grade);

	return 0;
}

STD get_max_stu(STD list[], int size) {//������ ���� ���� �л��� ã�� �Լ�
	STD max = list[0];
	for (int a = 1; a < size; a++) {
		if (list[a].grade > max.grade) {
			max = list[a];
		}
	}
	return max;
}