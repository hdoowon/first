#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int find(int a, int b, int k)
{
	char c;
	int m = (a + b) / 2;	//���ذ� ����� �д�
	if (a == b)
		return a;	//a, b�� �������ٸ� �� ���� k�̹Ƿ� a �� ��ȯ
	scanf(" %c", &c);	//�빮�� �Է�
	if (c == 'Y')	//y���
		find(m + 1, b, k);	//m + 1 �� k �� b �̹Ƿ� a�� ���� m + 1�� �ٲ۴�.
	else if (c == 'N')	//N�̶��
		find(a, m, k);	//a �� k �� m �̹Ƿ� b�� m���� �ٲ۴�.
}

int main(void)
{
	int a, b, k;

	scanf("%d %d %d", &a, &b, &k);	//������ ����k ����

	int e = find(a, b, k);	//����Ž�� �����Լ�
	printf("%d", e);	//ã�� ���

	return 0;
}