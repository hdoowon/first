#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rFE(int* arr, int k, int l, int r)	//이진탐색 재귀버전
{
	if (l > r)	//l이 r보다 커질때
		return r;	//r 반환
	int mid = (l + r) / 2;	//중간값 설정
	if (k == arr[mid])	//키가 같다면
		return mid;	//인덱스 반환
	else if (k < arr[mid])	//키가 더 작다면
		return rFE(arr, k, l, mid - 1);	//왼쪽으로 범위를 줄인다
	else if (k > arr[mid])	//키가 더 크다면
		return rFE(arr, k, mid + 1, r);	//오른쪽으로 범위를 줄인다
}

int findElement(int* arr, int n, int k)
{
	return rFE(arr, k, 0, n - 1);	//범위를 줄이면서 재귀함수 형태를 띄는 함수를 가져온다
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);	//배열 크기와 키 선언

	int* arr = (int*)malloc(sizeof(arr) * n);	//n크기의 배열 동적할당
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);	//배열에 값 넣기

	int e = findElement(arr, n, k);	//인덱스 찾기
	printf(" %d\n", e);

	return 0;
}