#include <stdio.h>
#pragma warning(disable: 4996)

int encrypt(char cipher[], int shift) //��ȣȭ �Լ�
{

	int i = 0;//index ����

	while (cipher[i] != '\0')//������ ��ġ�� 3��ŭ ���ڸ� �Ű��ִ� �˰���
	{
		if (cipher[i] >= 'a' && cipher[i] <= 'z') {
			cipher[i] += shift;//������ ��ġ�� 3��ŭ �Ű���

			if (cipher[i] > 'z')//z���� ū ��Ȳ�� ���� �ٽ� a���� �����ϰ� �ϴ� if��
				cipher[i] -= 26;
		}
		i++;
	}
	printf("��ȣȭ�� ���ڿ�: %s\n", cipher);//���
	return 0;
}

int recovery(char cipher[], int shift) //��ȣȭ �Լ�
{

	int i = 0;//index ����

	while (cipher[i] != '\0')//������ ��ġ�� ��ȣȭ �Ҷ� 3 ��ŭ �̵��� �־����� -3��ŭ �ǵ����� �ϴ� �˰���
	{
		if (cipher[i] >= 'a' && cipher[i] <= 'z') {
			cipher[i] -= shift;//������ ��ġ�� -3��ŭ �Ű���

			if (cipher[i] < 'a')//a���� ���� ��Ȳ �� ���� �ٽ� z�� �� �� �ְ� �ϴ� if ��
				cipher[i] += 26;
		}
		i++;
	}
	printf("��ȣȭ�� ���ڿ�: %s\n", cipher);//���
	return 0;
}



int main(void) {
	printf("=================\n�й�:202004026\n�̸�: �̻�\n=================\n");

	int num;//�޴��� ��ȣ ����
	char cipher[50];//�޴� ���ڿ��� ����
	int shift = 3;// �󸶳� �ű� ���� ��Ÿ���� ����

	printf("���ڿ��� �Է��ϼ���:");
	gets_s(cipher, 50);//���ڿ� �Է�

	while (1)
	{
		printf("1. ��ȣȭ 2. ��ȣȭ 0.���� \n�޴��� �Է��ϼ���: ");//�Է¹��� ���� �´� ������ �ϰ��� 
		scanf(" %d", &num);

		if (num == 1) {//��ȣȭ
			encrypt(cipher, shift);
		}
		else if (num == 2)//��ȣȭ
		{
			recovery(cipher, shift);
		}
		else if (num == 0)//����
		{
			printf("����");
			return 0;
		}
	}



	return 0;
}