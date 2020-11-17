#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	char name[100];//이름 받는 변수
	int name_num=0;//학번을 받는 변수
	char want_tell[100];//하고 싶은 말을 받는 변수

	printf("이름을 입력하세요:");
	gets_s(name, 100);//gets_s함수로 이름을 받음
	printf("학번을 입력하세요:");
	scanf("%d", &name_num);//scanf함수로 학번을 받음
	getchar();//버퍼 초기화
	printf("하고싶은 말을 써주세요.\n");
	gets_s(want_tell, 100);//gets_s함수로 하고 싶은 말을 받음

	printf("\n======결과 출력=======\n");//결과값 출력
	printf("이름:%s\n",name);
	printf("학번:%d\n",name_num);
	printf("하고싶은 말을 써주세요.\n%s",want_tell);

	return 0;
}