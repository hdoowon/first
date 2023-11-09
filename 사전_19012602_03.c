#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int find(int a, int b, int k)
{
	char c;
	int m = (a + b) / 2;	//기준값 가운데로 둔다
	if (a == b)
		return a;	//a, b가 같아진다면 그 값이 k이므로 a 값 반환
	scanf(" %c", &c);	//대문자 입력
	if (c == 'Y')	//y라면
		find(m + 1, b, k);	//m + 1 ≤ k ≤ b 이므로 a의 값을 m + 1로 바꾼다.
	else if (c == 'N')	//N이라면
		find(a, m, k);	//a ≤ k ≤ m 이므로 b를 m으로 바꾼다.
}

int main(void)
{
	int a, b, k;

	scanf("%d %d %d", &a, &b, &k);	//범위와 정수k 선언

	int e = find(a, b, k);	//이진탐생 응용함수
	printf("%d", e);	//찾고 출력

	return 0;
}