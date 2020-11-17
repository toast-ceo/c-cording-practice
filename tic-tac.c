#include <stdio.h>
#include<time.h>
#pragma warning (disable:4996)
void display(char board[][3]);// 보드 판을 보여주는 함수
int turn();
int check_board(char board[][3]); // 게임이 종료되었는지 검사하는 함수
int com(char board[][3]);
int user(char board[][3]);

int main(void) {
    printf("학번:202004026 이름: 이삭\n");
    //1. 상대방이 놓은곳에 다시 놓을 수 없게 해야함.
     //2. 게임이 종료되었는지 검사하는 함수가 필요
     //3. 컴퓨터가 자동으로 다음수를 결정하도록 프로그램을 변경
     //예) 비어있는 첫 번째 좌표에 놓음
    char board[3][3];
    int x, y, k, i, quit = 0, temp;
    //quit은 게임이 끝났는지 안끝났는지 판별하기 위해 사용하는 변수
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            board[x][y] = ' ';
        }
    }
    temp = turn();
    if (temp == 0) {
        do {
            do {
                display(board);
                printf("\n");
                quit = com(board);
                if (quit == 1) break;
                display(board);
                quit = user(board);
                quit = check_board(board);
            } while (quit == 0);
        } while (quit == 0);
    }
    else if(temp ==1){
        do {
            display(board);
            printf("\n");
            quit = user(board);
            if (quit == 1) break;
            display(board);
            quit = com(board);
            quit = check_board(board);
        } while (quit == 0);
    }
  

    return 0;
}
void display(char board[][3]) {
    for (int x = 0; x < 3; x++) {
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[x][0], board[x][1], board[x][2]);
    }
    printf("---|---|---\n");
}

int check_board(char board[][3]) {
    int i;
    char win = '-';
    for (i = 0; i < 3; i++) {
        //세로
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            win = 'X';
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            win = 'O';
        //가로 
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            win = 'X';
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
            win = 'O';
    }
    //대각선
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        win = 'X';
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        win = 'X';
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        win = 'O';
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        win = 'O';
    //승자 판별
    if (win == 'O' || win == 'X') {
        printf("승자는 %c \n", win);
        return 1;
    }
    return 0;
}

int com(char board[][3]) //컴퓨터가 순차적으로 놓는 부분
{
    int x, y;
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            if (board[x][y] == ' ') {
                board[x][y] = 'O';
                return 0;
            }
        }
    }
    return 1;
}
int user(char board[][3])
{
    int x, y, done = 0;
    do {
        printf("x,y 좌표 입력: ");
        scanf("%d %d", &x, &y);
        if (board[x][y] == ' ') {
            board[x][y] = 'X';
            done = 1;
        }
        else {
            printf("잘못된 위치입니다.");
            done = 0;
        }
    } while (done == 0);
    return 0;
}
int turn() {
    srand(time(NULL));
    int turn = rand() % 2; //이 경우 0 과 1이 나옴
    printf("\n--- %s 먼저 시작 ---\n", turn == 0 ? "컴퓨터가" : "사용자가");//랜덤 값에 따라 print출력
    if (turn == 0) {// 값에 따라서 return값을 바꿔준다.
        return 0;
    }
    else if(turn == 1) {
        return 1;
    }
}