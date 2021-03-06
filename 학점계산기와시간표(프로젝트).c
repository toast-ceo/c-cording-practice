#include <stdio.h>
#include <string.h>
#include<Windows.h>
#pragma warning(disable: 4996)

void creditcalculator(); // 계산기
void Timetable(); // 시간표
void Decoration(int n);//꾸미는 것
float gradeReturn(char grade[]);
void ui(char c[6][5]);

//시간표 구조체

struct timesubject {
	char subjectName[100];//과목이름
	char subjectIcon[6][5];//과목표시할 변수
};


//학점계산기 구조체
struct subject
{
	char name[30];//과목이름
	char grade[5];//학점
	int subjectTime; //과목에 배당된 학점
};

struct student
{
	float totalAve;//총점
	char name[10];//학생 이름
	struct subject sub[10];//과목 정보
};

int main() {
	int num;//메뉴 선택 변수
	while (1) {
		Decoration(1);
		printf("0.종료 1.학점 계산기 2.시간표 : ");
		scanf(" %d", &num);

		switch (num) {
			// 학점 계산기
		case 1:
			creditcalculator();
			break;
			// 시간표
		case 2:
			Timetable();
			break;
			//종료
		case 0:
			system("cls");
			printf("종료되었습니다!");
			return 0;
		}

	}
}

//기타
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

//학점 계산기
void creditcalculator() {
	struct student stu;
	int subjectNum;//학생의 과목 수

	//입력

	printf("\n이름:");
	scanf(" %s", &stu.name);
	system("cls");
	printf("입력하고 싶은 과목의 수:");
	scanf(" %d", &subjectNum);
	system("cls");

	for (int a = 0; a < subjectNum; a++) {
		printf("%d번째중 %d번째 과목 입력",subjectNum,a+1);
		Decoration(2);
		printf("%d번째 과목의 이름:", a + 1);
		scanf(" %s", stu.sub[a].name);
		printf("%d번째 과목의 학점[ex:A-]):", a + 1);
		scanf(" %s", stu.sub[a].grade);
		printf("과목에 배당된 학점:");
		scanf(" %d", &stu.sub[a].subjectTime);
		getchar();
		system("cls");
	}

	float temp = 0, sum = 0, plustemp = 0;//학점을 받아오는 변수, 총 더하는 변수, 배당된 학점을 더하는 변수
	//계산 로직
	for (int a = 0; a < subjectNum; a++) {
		temp = gradeReturn(stu.sub[a].grade);
		sum += (temp * stu.sub[a].subjectTime);
		plustemp += stu.sub[a].subjectTime;
	}
	stu.totalAve = sum / plustemp;//총점

	//출력
	Decoration(1);
	Sleep(100);
	printf("이름: %s 님\n\n", stu.name);
	Sleep(1000);
	for (int a = 0; a < subjectNum; a++) {
		printf("과목 이름(학점): %s(%s) \n", stu.sub[a].name, stu.sub[a].grade);
		Sleep(1000);
	}
	printf("이수 학점: %d\n", (int)plustemp);
	Sleep(1000);
	printf("학점 총점: %.2f / 4.3\n", stu.totalAve);
	printf("학점 총점: %.2f / 4.5\n", stu.totalAve * 1.046);
	printf("학점 총점: %.2f / 100\n\n", stu.totalAve * 23.255);
	Decoration(1);
	
	int arrow;
	printf("        확인하려면 아무 숫자나 입력하시요 : ");
	scanf("%d", &arrow);
	system("cls");
}


//학점을 점수로 변환
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
시간표 
입력(월, 교시, 과목, 과목아이콘)*/
void Timetable() {

	int num=5;//메뉴선택
	struct timesubject subtime[7];// 요일, 교시
	char uiIcon[7] = {'O','X', '=', '#', '*', 'H', 'Y' };//과목아이콘
	int vis[7] = { 0 };

	//초기화
	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 5; b++) {
			subtime[0].subjectIcon[a][b] = ' ';
		}
	}

	ui(subtime[0].subjectIcon);
	printf("과목 아이콘 : 과목 이름\n\n");
	for (int a = 0; a < 7; a++) {
		printf("     %c      :\n", uiIcon[a]);
	}
	Decoration(1);
	
	
	//메뉴
	while (num !=0)
	{
	
		printf("\n1.과목 등록  2.요일 입력 3.취소 4. 확인 0.종료: ");
		scanf(" %d", &num);
		system("cls");

		if (num == 1) //입력 //과목의 이름, 과목의 아이콘
		{
			char icontmp;
			int index;

			//과목 표시
			Decoration(1);
			printf("과목표시에 사용할 아이콘을 선택하시오['O','X', '=', '#', '*', 'H', 'Y'] :\n\n");
			Decoration(1);
			printf("   입력:");
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

			//과목 이름
			printf("과목 이름을 쓰시오 : ");
			scanf(" %s", &subtime[index].subjectName);
			system("cls");

			vis[index] = 1;
			printf("과목 아이콘 : 과목 이름\n\n");
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
		else if (num == 2) { //요일 등록
			int index_1 = 0, index_2 = 0; char day[10], icontmp;

			ui(subtime[0].subjectIcon);
			printf("과목 아이콘 : 과목 이름\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);
			printf("시간표 표시에 사용할 아이콘을 선택하시오['O','X', '=', '#', '*', 'H', 'Y'] :");
			scanf(" %c", &icontmp);
			getchar();
			printf("요일과 교시를 쓰시오 (요일은 알파벳으로 교시는 숫자로 표시하시오(요일: A~E / 교시: 1~6)\n[ex: 화요일 4교시 : B4, 목요일 2교시 : D2 ] :  ");
			gets(day);
			system("cls");

			//확인
			
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

			//출력
			ui(subtime[0].subjectIcon);
			printf("과목 아이콘 : 과목 이름\n\n");
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

		else if (num == 3) {//취소

		int cancelnum;
		int index_1 = 0, index_2 = 0; char day1[10], icontmp1;

		printf("1. 취소 하고 싶은 과목 2. 취소하고 싶은 요일 & 교시 시간표 아이콘\n");
		scanf(" %d", &cancelnum);
		system("cls");
		
		if (cancelnum == 1) {

			Decoration(1);
			printf("과목 아이콘 : 과목 이름\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);

			printf("취소 하고 싶은 과목의 아이콘을 쓰시오: ");
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
			printf("과목 아이콘 : 과목 이름\n\n");
			for (int a = 0; a < 7; a++) {
				if (vis[a] == 1) {
					printf("     %c      : %s \n", uiIcon[a], subtime[a].subjectName);
				}
				else {
					printf("     %c      : \n", uiIcon[a]);
				}
			}
			Decoration(1);
			printf("취소 하고 싶은 요일과 교시를 쓰시오\n(요일은 알파벳으로 교시는 숫자로 표시하시오[ex: B4, D2 ] :  ");
			scanf(" %s", day1);
			system("cls");

			//확인

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

		//출력
		ui(subtime[0].subjectIcon);
		printf("과목 아이콘 : 과목 이름\n\n");
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

		else if (num == 4) {//확인

		ui(subtime[0].subjectIcon);
		printf("과목 아이콘 : 과목 이름\n\n");
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

	printf("           월    화   수    목    금\n");
	
	Decoration(2);
	//시간표 표시해주는 곳
	for (int a = 0; a < 6; a++) {
		printf("%d period",a+1);
		for (int b = 0; b < 5; b++) {
			printf("  %c  |", c[a][b]);
		}
		printf("\n");
	}
	Decoration(2);

};

