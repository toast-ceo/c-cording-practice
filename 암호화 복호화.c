#include <stdio.h>
#pragma warning(disable: 4996)

int encrypt(char cipher[], int shift) //암호화 함수
{

	int i = 0;//index 변수

	while (cipher[i] != '\0')//문자의 위치를 3만큼 문자를 옮겨주는 알고리즘
	{
		if (cipher[i] >= 'a' && cipher[i] <= 'z') {
			cipher[i] += shift;//문자의 위치를 3만큼 옮겨줌

			if (cipher[i] > 'z')//z보다 큰 상황일 때의 다시 a부터 시작하게 하는 if문
				cipher[i] -= 26;
		}
		i++;
	}
	printf("암호화된 문자열: %s\n", cipher);//출력
	return 0;
}

int recovery(char cipher[], int shift) //복호화 함수
{

	int i = 0;//index 변수

	while (cipher[i] != '\0')//문자의 위치를 암호화 할때 3 만큼 이동해 주었으니 -3만큼 되돌리게 하는 알고리즘
	{
		if (cipher[i] >= 'a' && cipher[i] <= 'z') {
			cipher[i] -= shift;//문자의 위치를 -3만큼 옮겨줌

			if (cipher[i] < 'a')//a보다 작은 상황 일 때의 다시 z로 갈 수 있게 하는 if 문
				cipher[i] += 26;
		}
		i++;
	}
	printf("복호화된 문자열: %s\n", cipher);//출력
	return 0;
}



int main(void) {
	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	int num;//메뉴의 번호 변수
	char cipher[50];//받는 문자열의 변수
	int shift = 3;// 얼마나 옮길 건지 나타내는 변수

	printf("문자열을 입력하세요:");
	gets_s(cipher, 50);//문자열 입력

	while (1)
	{
		printf("1. 암호화 2. 복호화 0.종료 \n메뉴를 입력하세요: ");//입력받은 수에 맞는 동작을 하게함 
		scanf(" %d", &num);

		if (num == 1) {//암호화
			encrypt(cipher, shift);
		}
		else if (num == 2)//복호화
		{
			recovery(cipher, shift);
		}
		else if (num == 0)//종료
		{
			printf("종료");
			return 0;
		}
	}



	return 0;
}