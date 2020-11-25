#include <stdio.h>
#pragma warning(disable: 4996)

typedef struct student {
	int num;
	char name[20];
	double grade;
}STD;

STD get_max_stu(STD list[], int size);

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	STD list[3];
	int size = sizeof(list) / sizeof(list[0]);
	
	for (int a = 0; a < size; a++) {//구조체 정보 받는 곳
	
		printf("이름");
		scanf("%s", list[a].name);
		
		printf("학번");
		scanf("%d", &list[a].num);
			
		printf("학점");
		scanf("%lf", &list[a].grade);
		
		getchar();
	}
	STD max = get_max_stu(list, size);

	//결과
	printf("평점이 가장 높은 학생은 (이름:%s, 학번: %d, 학점: %lf)",max.name,max.num,max.grade);

	return 0;
}

STD get_max_stu(STD list[], int size) {//학점이 가장 높은 학생을 찾는 함수
	STD max = list[0];
	for (int a = 1; a < size; a++) {
		if (list[a].grade > max.grade) {
			max = list[a];
		}
	}
	return max;
}