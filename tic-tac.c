#include <stdio.h>
#include<time.h>
#pragma warning (disable:4996)
void display(char board[][3]);// ���� ���� �����ִ� �Լ�
int turn();
int check_board(char board[][3]); // ������ ����Ǿ����� �˻��ϴ� �Լ�
int com(char board[][3]);
int user(char board[][3]);

int main(void) {
    printf("�й�:202004026 �̸�: �̻�\n");
    //1. ������ �������� �ٽ� ���� �� ���� �ؾ���.
     //2. ������ ����Ǿ����� �˻��ϴ� �Լ��� �ʿ�
     //3. ��ǻ�Ͱ� �ڵ����� �������� �����ϵ��� ���α׷��� ����
     //��) ����ִ� ù ��° ��ǥ�� ����
    char board[3][3];
    int x, y, k, i, quit = 0, temp;
    //quit�� ������ �������� �ȳ������� �Ǻ��ϱ� ���� ����ϴ� ����
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
        //����
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            win = 'X';
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            win = 'O';
        //���� 
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            win = 'X';
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
            win = 'O';
    }
    //�밢��
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        win = 'X';
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        win = 'X';
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        win = 'O';
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        win = 'O';
    //���� �Ǻ�
    if (win == 'O' || win == 'X') {
        printf("���ڴ� %c \n", win);
        return 1;
    }
    return 0;
}

int com(char board[][3]) //��ǻ�Ͱ� ���������� ���� �κ�
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
        printf("x,y ��ǥ �Է�: ");
        scanf("%d %d", &x, &y);
        if (board[x][y] == ' ') {
            board[x][y] = 'X';
            done = 1;
        }
        else {
            printf("�߸��� ��ġ�Դϴ�.");
            done = 0;
        }
    } while (done == 0);
    return 0;
}
int turn() {
    srand(time(NULL));
    int turn = rand() % 2; //�� ��� 0 �� 1�� ����
    printf("\n--- %s ���� ���� ---\n", turn == 0 ? "��ǻ�Ͱ�" : "����ڰ�");//���� ���� ���� print���
    if (turn == 0) {// ���� ���� return���� �ٲ��ش�.
        return 0;
    }
    else if(turn == 1) {
        return 1;
    }
}