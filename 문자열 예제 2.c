#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");

	char str1[6] = "Seoul";//str1 �迭�� 0~4�� �ε������� ���� seoul�� �ʱ�ȭ, 5�� �ε������� \0�� �ʱ�ȭ
	char str2[3] = { 'i','s','\0' }; //str2 �迭�� 0,1�� �ε����� ���� is�� �ʱ�ȭ 2�� �ε������� \0���� �ʱ�ȭ
	char str3[] = "the capital city of Korea.";//str3 �迭���� the capital city of Korea. ��� ���ڸ� ���� �ʱ�ȭ ���ְ� .�� �ʱ�ȭ�� �ε��� +1�� \0���� �ʱ�ȭ  
	printf("%s %s %s\n", str1, str2, str3); // �迭�� ���� ���
	return 0;

}