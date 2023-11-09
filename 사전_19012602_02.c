#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void findElement(int* arr, int k, int n)
{
	int mid = n / 2;	//기준값 인덱스 설정
	if (arr[mid] == k)
		printf(" %d", mid);	//기준값과 키와 같다면 인덱스 출력
	else if (arr[mid] > k)	//키보다 기준값이 크다면
	{
		for (int j = 0; j < mid; j++)	//기준값 왼쪽값을 반복
		{
			if (arr[j] == k) {
				printf(" %d\n", j);	//같다면 출력
				break;
			}
			else if (arr[j] > k) {	//키가 작다면
				if (j == 0) {	//0일때는 0
					printf(" 0\n");
					break;
				}
				else {
					printf(" %d\n", j);	//j출력
					break;
				}
			}
			else if (arr[j] < k)	//키가 크다면 계속해준다
				continue;
		}
	}
	else if (arr[mid] < k)	//키보다 기준값이 작다면
	{
		for (int i = n; i > mid; i--)	//기준값 오른값을 반복
		{
			if (arr[i] == k) {
				printf(" %d\n", i);	//같다면 출력
				break;
			}
			else if (arr[i] < k) {	//키가 크다면
				if (i == n) //최대 배열값이라면
				{
					printf(" %d\n", n + 1);	//n+1 출력
					break;
				}
				else {
					printf(" %d\n", i + 1);	//아니라면 i+1출력
					break;
				}
			}
			else if (arr[i] > k)	//키가 크다면 계속해준다
				continue;
		}
	}
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);	//사전에서 찾을 원소와 위치 입력

	int* arr = (int*)malloc(sizeof(int) * n);	//배열 동적할당
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);	//배열에 값 입력

	findElement(arr, k, n - 1);

	return 0;
}