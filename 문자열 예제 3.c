#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	char src[] = "The worst things to eat before you sleep";//원본 문자를 담을 배열을 선언, []으로 초기화 하는 방법으로 초기화 시켜줌, 초기화의 마지막 값은 \0
	char dst[100];// 원본을 복사시킬 배열을 선언, 인덱스 값은 넉넉하게 100으로 선언
	int i;//반복문을 통해 배열을 복사시키기 위해 사용할 i변수 선언
	printf("원본 문자열=%s\n", src);//원본 문자 배열(src) 출력
	for (i = 0; src[i] != '\0'; i++)//비어있는 dst배열을 반복문을 사용하여 일일히 대입함으로 복사시켜줌 / 조건: 원본 문자 배열의 마지막 값인 \0를 만날 때까지 반복
		dst[i] = src[i];
	dst[i] = '\0';//인덱스가 i번째일 때 초기값은 \0으로 해줌
	printf("복사된 문자열=%s\n", dst);//복사된 문자열을 출력

	return 0;
}