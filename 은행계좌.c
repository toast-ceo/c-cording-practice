#include<stdio.h>
#pragma warning(disable:4996)

int money; // 전역변수로 잔액 정의, 0으로 초기화 되어있음.

void save(int x) // 저축 함수
{
	money += x;
	printf("총 금액 : %d 원\n", money);
}

void draw(int x) // 인출 함수 
{
	
	if (x < money) // 잔액과 인출 금액 비교 후 계산.
	{
		money -= x;
		printf("총 금액 : %d 원\n", money);
	}
	else
	{
		printf("잔액이 부족합니다.\n");
		printf("총 금액 : %d원\n", money);
	}
}

void print() // 잔액 확인 함수 
{
	printf("총 금액 : %d원\n", money);
}

int main()
{
	int menu_num, amount=0; // 메뉴 숫자. 돈 정의  

	printf("학번 : 202004026 이름: 이삭\n");

	do // 메뉴에 맞게 조건문 설정 및 종료 전까지 무한으로 돌게 반복문 설정. 
	{
		printf("메뉴를 선택하세요\n 1. 저축 2. 인출 3. 잔액확인 0. 종료 :");
		scanf("%d",&menu_num);

		if (menu_num == 0) 
			break;

		else if (menu_num == 1) {
			printf("저축할 금액을 입력하세요 : ");
			scanf("%d", &amount);
			save(amount);
		}
		else if (menu_num == 2) {
			printf("인출할 금액을 입력하세요 : ");
			scanf("%d", &amount);
			draw(amount);
		}
		else if (menu_num == 3) {
			print();
		} 
		else
			printf("잘못입력하셨습니다.\n");

	} while (1);

	printf("종료!");
}

