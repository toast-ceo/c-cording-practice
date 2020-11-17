#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

struct book { //BOOK 구조체 선언
	char book_name[20]; // 이름 변수
	char writer[10];// 작가
	int price; // 가격
	char genre[10]; //장르
};
int main(void) {

	printf("=================\n학번:202004026\n이름: 이삭\n=================\n");

	int num; // 장르 선택 받는 변수
	struct book booklist[3];//booklist변수를 3번 받기위해 배열로 선언

	for (int a = 0; a < 3; a++) {// 3번 받는 반복문

		printf("책 이름:");//책이름을 받음
		gets_s(booklist[a].book_name,20);
	

		printf("작가 이름:"); //작가 이름을 받음
		gets_s(booklist[a].writer, 10);
		

		printf("장르 : 1. 소설 2. 에세이 3. 교육\n");// 장르를 번호 입력에 따라서 받을 수 있게함
		scanf(" %d", &num);
	

		switch (num)//각각 1, 2, 3의 경우일 때 받음
		{
		case 1:
			strcpy(booklist[a].genre, "소셜");
			break;
		case 2:
			strcpy(booklist[a].genre, "에세이");
			break;
		case 3:
			strcpy(booklist[a].genre, "교육");
			break;
		}

		printf("가격:");//가격을 받음
		scanf(" %d", &booklist[a].price);
		getchar();
	}

	printf("=======결과======\n");
	for (int a = 0; a < 3;a++) {//결과 값 출력
		printf("책 이름:%s\n", booklist[a].book_name);
		printf("작가 이름:%s\n", booklist[a].writer);
		printf("장르:%s\n", booklist[a].genre);
		printf("가격:%d\n", booklist[a].price);

	};
	return 0;
}




