#include <stdio.h>
#pragma warning(disable: 4996)


int check(char s[], char a[], char ch)//�Է¹��� ���� ����� ������ ���ϴ� �Լ� 
{
	int i;
	for (i = 0; s[i] != NULL; i++) //����� ���� ��� _�ٸ� ���ĺ����� �ٲ���
	{
		if (s[i] == ch)
			a[i] = ch;
	}
	if (strcmp(s, a) == 0)
		return 1; // ����� ��ġ�ϴ����� �˻�
	else return 0;
}

void alpabet(char temp) {//����� ���ĺ��� *�� �ٲ��ִ� �Լ�
	for (int a = 0; a < 26; a++) {
		if (alpa[a] == temp) {
			alpa[a] = '*';
			return 0;
		}
	}
}

int main(void) {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");

	char solution[50] = "hello world";//������ ������ �ִ� ����
	char answer[50] = "_____ _____";//���� ���� ��Ÿ���ִ� ����
	char ch;//�Է¹޴� ����
	char alpa[26];


	for (int a = 0; a < 26; a++) alpa[a] = 97 + a;//alpa������ ���ĺ��� �־��ִ� �˰���


	for (int b = 10; b > 0; b--) {//��ü ��ȸ�� 10������ �ֱ� ������ 10�� ������ �ݺ���
		
	
		printf("===��ȸ : %d ȸ =====\n", b);//���� ��ȸ�� ǥ��
		printf("�����ִ� ����:%s\n", alpa);//�����ִ� ���ĺ��� ǥ��
		printf("���ڿ��� �Է��Ͻÿ�: %s \n", answer);//�Է¹ޱ��� ���ݱ����� ��Ȳ ��Ÿ���ִ� printf
		printf("���ڸ� �����Ͻÿ�: ");
		ch = getchar();

		alpabet(ch);

		if (check(solution, answer, ch) == 1)//������ ��� �ݺ����� ������ ����
			break;
		fflush(stdin); // �ٹٲ� ���� ����

		getchar();
}

	printf("����");
	return 0;
}