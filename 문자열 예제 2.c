#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	char str1[6] = "Seoul";//str1 배열의 0~4의 인덱스까지 각각 seoul로 초기화, 5의 인덱스에서 \0로 초기화
	char str2[3] = { 'i','s','\0' }; //str2 배열의 0,1의 인덱스에 각각 is로 초기화 2의 인덱스에서 \0으로 초기화
	char str3[] = "the capital city of Korea.";//str3 배열에게 the capital city of Korea. 라는 문자를 각각 초기화 해주고 .을 초기화한 인덱스 +1에 \0으로 초기화  
	printf("%s %s %s\n", str1, str2, str3); // 배열의 값을 출력
	return 0;

}