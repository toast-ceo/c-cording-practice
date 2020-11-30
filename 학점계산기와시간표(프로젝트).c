#include <stdio.h>
#include <string.h>
#include<Windows.h>
#pragma warning(disable: 4996)

void creditcalculator(); // ����
void Timetable(); // �ð�ǥ
void Decoration(int n);//�ٹ̴� ��
float gradeReturn(char grade[]);
void ui(char c[6][5]);

//�ð�ǥ ����ü

struct timesubject {
	char subjectName[100];//�����̸�
	char subjectIcon[6][5];//����ǥ���� ����
};


//�������� ����ü
struct subject
{
	char name[30];//�����̸�
	char grade[5];//����
	int subjectTime; //���� ���� ����
};

struct student
{
	float totalAve;//����
	char name[10];//�л� �̸�
	struct subject sub[10];//���� ����
};

int main() {
	int num;//�޴� ���� ����
	while (1) {
		Decoration(1);
		printf("0.���� 1.���� ���� 2.�ð�ǥ : ");
		scanf(" %d", &num);

		switch (num) {
			// ���� ����
		case 1:
			creditcalculator();
			break;
			// �ð�ǥ
		case 2:
			Timetable();
			break;
			//����
		case 0:
			system("cls");
			printf("����Ǿ����ϴ�!");
			return 0;
		}

	}
}

//��Ÿ
void Decoration(int n) {
	switch (n)
	{
	case 1:
		printf("===============================================================================\n\n");
		break;
	case 2:
		printf("-------------------------------------------------------------------------------\n");
		break;

	}
}

//���� ����
void creditcalculator() {
	struct student stu;
	int subjectNum;//�л��� ���� ��

	//�Է�

	printf("\n�̸�:");
	scanf(" %s", &stu.name);
	system("cls");
	printf("�Է��ϰ� ���� ������ ��:");
	scanf(" %d", &subjectNum);
	system("cls");

	for (int a = 0; a < subjectNum; a++) {
		printf("%d��°�� %d��° ���� �Է�",subjectNum,a+1);
		Decoration(2);
		printf("%d��° ������ �̸�:", a + 1);
		scanf(" %s", stu.sub[a].name);
		printf("%d��° ������ ����[ex:A-]):", a + 1);
		scanf(" %s", stu.sub[a].grade);
		printf("���� ���� ����:");
		scanf(" %d", &stu.sub[a].subjectTime);
		getchar();
		system("cls");
	}

	float temp = 0, sum = 0, plustemp = 0;//������ �޾ƿ��� ����, �� ���ϴ� ����, ���� ������ ���ϴ� ����
	//��� ����
	for (int a = 0; a < subjectNum; a++) {
		temp = gradeReturn(stu.sub[a].grade);
		sum += (temp * stu.sub[a].subjectTime);
		plustemp += stu.sub[a].subjectTime;
	}
	stu.totalAve = sum / plustemp;//����

	//���
	Decoration(1);
	Sleep(100);
	printf("�̸�: %s ��\n\n", stu.name);
	Sleep(1000);
	for (int a = 0; a < subjectNum; a++) {
		printf("���� �̸�(����): %s(%s) \n", stu.sub[a].name, stu.sub[a].grade);
		Sleep(1000);
	}
	printf("�̼� ����: %d\n", (int)plustemp);
	Sleep(1000);
	printf("���� ����: %.2f / 4.3\n", stu.totalAve);
	printf("���� ����: %.2f / 4.5\n", stu.totalAve * 1.046);
	printf("���� ����: %.2f / 100\n\n", stu.totalAve * 23.255);
	Decoration(1);
	
	int arrow;
	printf("        Ȯ���Ϸ��� �ƹ� ���ڳ� �Է��Ͻÿ� : ");
	scanf("%d", &arrow);
	system("cls");
}


//������ ������ ��ȯ
float gradeReturn(char grade[]) {
	float g = 0;
	if (grade[0] == 'A' || grade[0] == 'a')
	{
		g += 4;
	}
	else if (grade[0] == 'B' || grade[0] == 'b')
	{
		g += 3;
	}
	else if (grade[0] == 'C' || grade[0] == 'c')
	{
		g += 2;
	}
	else if (grade[0] == 'D' || grade[0] == 'd')
	{
		g += 1;
	}
	else if (grade[0] == 'F' || grade[0] == 'f') {
		g = 0;
	}

	if (grade[1] == '+')
	{
		g += 0.3;
	}
	else if (grade[1] == '-')
	{
		g -= 0.3;
	}

	return g;
}


/*
�ð�ǥ 
�Է�(��, ����, ����, ���������)*/
void Timetable() {

	int num=5;//�޴�����
	struct timesubject subtime[7];// ����, ����
	char uiIcon[7] = {'O','X', '=', '#', '*', 'H', 'Y' };//���������
	int vis[7] = { 0 };

	//�ʱ�ȭ
	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 5; b++) {
			subtime[0].subjectIcon[a][b] = ' ';
		}
	}

	ui(subtime[0].subjectIcon);
	printf("���� ������ : ���� �̸�\n\n");
	for (int a = 0; a < 7; a++) {
		printf("     %c      :\n", uiIcon[a]);
	}
	Decoration(1);
	
	
	//�޴�
	while (num !=0)
	{
	
		printf("\n1.���� ���  2.���� �Է� 3.��� 4. Ȯ�� 0.����: ");
		scanf(" %d", &num);
		system("cls");

		if (num == 1) //�Է� //������ �̸�, ������ ������
		{
			char icontmp;
			int index;

			//���� ǥ��
			Decoration(1);
			printf("����ǥ�ÿ� ����� �������� �����Ͻÿ�['O','X', '=', '#', '*', 'H', 'Y'] :\n\n");
			Decoration(1);
			printf("   �Է�:");
			scanf(" %c", &icontmp);
			system("cls");

		
			if (uiIcon[0] == icontmp) {
				index = 0;
			}
			else if (uiIcon[1] == icontmp) {
				index = 1;
			}
			else if (uiIcon[2] == icontmp) {
				index = 2;
			}
			else if (uiIcon[3] == icontmp) {
				index = 3;
			}
			else if (uiIcon[4] == icontmp) {
				index = 4;
			}
			else if (uiIcon[5] == icontmp) {
				index = 5;
			}
			else if (uiIcon[6] == icontmp) {
				index = 6;
			}

			//���� �̸�
			printf("���� �̸��� ���ÿ� : ");
			scanf(" %s", &subtime[index].subjectName);
			system("cls");

			vis[index] = 1;
			printf("���� ������ : ���� �̸�\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);
				
		}
		else if (num == 2) { //���� ���
			int index_1 = 0, index_2 = 0; char day[10], icontmp;

			ui(subtime[0].subjectIcon);
			printf("���� ������ : ���� �̸�\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);
			printf("�ð�ǥ ǥ�ÿ� ����� �������� �����Ͻÿ�['O','X', '=', '#', '*', 'H', 'Y'] :");
			scanf(" %c", &icontmp);
			getchar();
			printf("���ϰ� ���ø� ���ÿ� (������ ���ĺ����� ���ô� ���ڷ� ǥ���Ͻÿ�(����: A~E / ����: 1~6)\n[ex: ȭ���� 4���� : B4, ����� 2���� : D2 ] :  ");
			gets(day);
			system("cls");

			//Ȯ��
			
			if (day[0] == 'A') {
				index_1 = 0;
			}
			else if (day[0] == 'B') {
				index_1 = 1;
			}
			else if (day[0] == 'C') {
				index_1 = 2;
			}
			else if (day[0] == 'D') {
				index_1 = 3;
			}
			else if (day[0] == 'F') {
				index_1 = 4;
			}
			if (day[1] == '1') {
				index_2 = 0;
			}
			else if (day[1] == '2') {
				index_2 = 1;
			}
			else if (day[1] == '3') {
				index_2 = 2;
			}
			else if (day[1] == '4') {
				index_2 = 3;
			}
			else if (day[1] == '5') {
				index_2 = 4;
			}
			else if (day[1] == '6') {
				index_2 = 5;
			}


			subtime[0].subjectIcon[index_2][index_1] = icontmp;

			//���
			ui(subtime[0].subjectIcon);
			printf("���� ������ : ���� �̸�\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);
		}

		else if (num == 3) {//���

		int cancelnum;
		int index_1 = 0, index_2 = 0; char day1[10], icontmp1;

		printf("1. ��� �ϰ� ���� ���� 2. ����ϰ� ���� ���� & ���� �ð�ǥ ������\n");
		scanf(" %d", &cancelnum);
		system("cls");
		
		if (cancelnum == 1) {

			Decoration(1);
			printf("���� ������ : ���� �̸�\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);

			printf("��� �ϰ� ���� ������ �������� ���ÿ�: ");
			scanf(" %c", &icontmp1);
			system("cls");

			for (int a = 0; a < 7; a++) {
				if (uiIcon[a] == icontmp1) {
					strcpy(subtime[a].subjectName, " ");
				}
			}

		}
		else if (cancelnum == 2) {
			ui(subtime[0].subjectIcon);
			printf("���� ������ : ���� �̸�\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);
			printf("��� �ϰ� ���� ���ϰ� ���ø� ���ÿ�\n(������ ���ĺ����� ���ô� ���ڷ� ǥ���Ͻÿ�[ex: B4, D2 ] :  ");
			scanf(" %s", day1);
			system("cls");

			//Ȯ��

			if (day1[0] == 'A') {
				index_1 = 0;
			}
			else if (day1[0] == 'B') {
				index_1 = 1;
			}
			else if (day1[0] == 'C') {
				index_1 = 2;
			}
			else if (day1[0] == 'D') {
				index_1 = 3;
			}
			else if (day1[0] == 'F') {
				index_1 = 4;
			}
			if (day1[1] == '1') {
				index_2 = 0;
			}
			else if (day1[1] == '2') {
				index_2 = 1;
			}
			else if (day1[1] == '3') {
				index_2 = 2;
			}
			else if (day1[1] == '4') {
				index_2 = 3;
			}
			else if (day1[1] == '5') {
				index_2 = 4;
			}
			else if (day1[1] == '6') {
				index_2 = 5;
			}
			subtime[0].subjectIcon[index_2][index_1] = ' ';
		}

		//���
		ui(subtime[0].subjectIcon);
		printf("���� ������ : ���� �̸�\n\n");
		for (int a = 0; a < 7; a++) {
			if (vis[a] == 1) {
				printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
			}
			else {
				printf("     %c      : \n", uiIcon[a]);
			}
		}
		Decoration(1);

		}

		else if (num == 4) {//Ȯ��

		ui(subtime[0].subjectIcon);
		printf("���� ������ : ���� �̸�\n\n");
		for (int a = 0; a < 7; a++) {
			if (vis[a] == 1) {
				printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
			}
			else {
				printf("     %c      : \n", uiIcon[a]);
			}
		}
		Decoration(1);
		}
	}
	system("cls");
}

void ui(char c[6][5]) {
	Decoration(1);

	printf("           ��    ȭ   ��    ��    ��\n");
	
	Decoration(2);
	//�ð�ǥ ǥ�����ִ� ��
	for (int a = 0; a < 6; a++) {
		printf("%d period",a+1);
		for (int b = 0; b < 5; b++) {
			printf("  %c  |", c[a][b]);
		}
		printf("\n");
	}
	Decoration(2);

};

