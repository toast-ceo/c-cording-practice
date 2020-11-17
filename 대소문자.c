#include<ctype.h>
#include <stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");//학번 입력
	char lettering[100]; //문자열 받는 배열
	int big_num=0, small_num=0;// 대소문자가 몇개인지 표현할 변수
	
	printf("문자열을 입력하세요:");
	gets_s(lettering, 100);//gets_s함수로 문자열 받음

	for (int a = 0; a<strlen(lettering); a++) {//포문을 통해 문자열에 있는 문자를 대소문자로 구별
		if (isupper(lettering[a])) {
			big_num++;
		}
		if (islower(lettering[a])) {
			small_num++;
		}
	}

	printf("'%s'의 문자길이: %d\n", lettering, strlen(lettering));//결과값을 내보냄
	printf("대문자의 개수: %d\n", big_num);
	printf("소문자의 개수: %d\n", small_num);

	return 0;
}