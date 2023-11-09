#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rFE(int* arr, int k, int l, int r)	//����Ž�� ��͹���
{
	if (l > r)	//l�� r���� Ŀ����
		return r;	//r ��ȯ
	int mid = (l + r) / 2;	//�߰��� ����
	if (k == arr[mid])	//Ű�� ���ٸ�
		return mid;	//�ε��� ��ȯ
	else if (k < arr[mid])	//Ű�� �� �۴ٸ�
		return rFE(arr, k, l, mid - 1);	//�������� ������ ���δ�
	else if (k > arr[mid])	//Ű�� �� ũ�ٸ�
		return rFE(arr, k, mid + 1, r);	//���������� ������ ���δ�
}

int findElement(int* arr, int n, int k)
{
	return rFE(arr, k, 0, n - 1);	//������ ���̸鼭 ����Լ� ���¸� ��� �Լ��� �����´�
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);	//�迭 ũ��� Ű ����

	int* arr = (int*)malloc(sizeof(arr) * n);	//nũ���� �迭 �����Ҵ�
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);	//�迭�� �� �ֱ�

	int e = findElement(arr, n, k);	//�ε��� ã��
	printf(" %d\n", e);

	return 0;
}