#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void findElement(int* arr, int k, int n)
{
	int mid = n / 2;	//���ذ� �ε��� ����
	if (arr[mid] == k)
		printf(" %d", mid);	//���ذ��� Ű�� ���ٸ� �ε��� ���
	else if (arr[mid] > k)	//Ű���� ���ذ��� ũ�ٸ�
	{
		for (int j = 0; j < mid; j++)	//���ذ� ���ʰ��� �ݺ�
		{
			if (arr[j] == k) {
				printf(" %d\n", j);	//���ٸ� ���
				break;
			}
			else if (arr[j] > k) {	//Ű�� �۴ٸ�
				if (j == 0) {	//0�϶��� 0
					printf(" 0\n");
					break;
				}
				else {
					printf(" %d\n", j);	//j���
					break;
				}
			}
			else if (arr[j] < k)	//Ű�� ũ�ٸ� ������ش�
				continue;
		}
	}
	else if (arr[mid] < k)	//Ű���� ���ذ��� �۴ٸ�
	{
		for (int i = n; i > mid; i--)	//���ذ� �������� �ݺ�
		{
			if (arr[i] == k) {
				printf(" %d\n", i);	//���ٸ� ���
				break;
			}
			else if (arr[i] < k) {	//Ű�� ũ�ٸ�
				if (i == n) //�ִ� �迭���̶��
				{
					printf(" %d\n", n + 1);	//n+1 ���
					break;
				}
				else {
					printf(" %d\n", i + 1);	//�ƴ϶�� i+1���
					break;
				}
			}
			else if (arr[i] > k)	//Ű�� ũ�ٸ� ������ش�
				continue;
		}
	}
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);	//�������� ã�� ���ҿ� ��ġ �Է�

	int* arr = (int*)malloc(sizeof(int) * n);	//�迭 �����Ҵ�
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);	//�迭�� �� �Է�

	findElement(arr, k, n - 1);

	return 0;
}