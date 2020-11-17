#include <stdio.h>
#pragma warning(disable: 4996)


int check(char s[], char a[], char ch)//입력받은 값과 정답과 같은지 비교하는 함수 
{
	int i;
	for (i = 0; s[i] != NULL; i++) //정답과 같을 경우 _바를 알파벳으로 바꿔줌
	{
		if (s[i] == ch)
			a[i] = ch;
	}
	if (strcmp(s, a) == 0)
		return 1; // 정답과 일치하는지를 검사
	else return 0;
}

void alpabet(char temp) {//사용한 알파벳을 *로 바꿔주는 함수
	for (int a = 0; a < 26; a++) {
		if (alpa[a] == temp) {
			alpa[a] = '*';
			return 0;
		}
	}
}

int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	char solution[50] = "hello world";//정답을 가지고 있는 변수
	char answer[50] = "_____ _____";//글자 수를 나타내주는 변수
	char ch;//입력받는 변수
	char alpa[26];


	for (int a = 0; a < 26; a++) alpa[a] = 97 + a;//alpa변수에 알파벳을 넣어주는 알고리즘


	for (int b = 10; b > 0; b--) {//전체 기회를 10번으로 주기 때문에 10번 돌리는 반복문
		
	
		printf("===기회 : %d 회 =====\n", b);//남은 기회를 표시
		printf("남아있는 문자:%s\n", alpa);//남아있는 알파벳을 표현
		printf("문자열을 입력하시오: %s \n", answer);//입력받기전 지금까지의 현황 나타내주는 printf
		printf("글자를 추측하시오: ");
		ch = getchar();

		alpabet(ch);

		if (check(solution, answer, ch) == 1)//정답일 경우 반복문을 나가게 해줌
			break;
		fflush(stdin); // 줄바꿈 문자 제거

		getchar();
}

	printf("정답");
	return 0;
}