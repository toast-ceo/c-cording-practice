#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	int i;//배열의 인덱스를 바꿔주기 위한 변수
	char str[4];//문자를 넣을 배열(변수) 선언
	str[0] = 'a';//str[0]에 a를 선언
	str[1] = 'b';//str[1]에 b를 선언
	str[2] = 'c';//str[2]에 c를 선언
	str[3] = '\0';//NULL문자를 넣어줌으로 끝남을 표시
	i = 0;//인덱스를 0으로 정함
	while (str[i] != '\0') {//str의 변수가 \0이 아닐경우 반복문을 계속 돌림
		printf("%c", str[i]);// 배열의 값 출력
		i++;//인덱스를 바꿔주기 위한 증감표시
	}

	return 0;
}