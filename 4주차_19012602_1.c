#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 100

int H[MAX_HEAP_SIZE]; // 전역 배열로 힙 선언
int n = 0; // 현재 총 키 개수

void downHeap(int i) {	// 3주차와 동일함
    int key = H[i];
    int child;
    while (i <= n / 2) {
        child = 2 * i;
        if (child < n && H[child] < H[child + 1]) {
            child++;
        }
        if (key >= H[child]) {
            break;
        }
        H[i] = H[child];
        i = child;
    }
    H[i] = key;
}

void inPlaceHeapSort() {
    for (int i = n / 2; i >= 1; i--) {	// 힙 생성
        downHeap(i);
    }

    for (int i = n; i > 1; i--) {   // root 노드를 하나씩 빼서 정렬
        int temp = H[1];
        H[1] = H[i];
        H[i] = temp;
        n--;

        downHeap(1);
    }
}

void printArray(int num) {
    for (int i = 1; i <= num; i++) {
        printf(" %d", H[i]);
    }
    printf("\n");
}

int main() {
    int num; // 키 개수

    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        scanf("%d", &H[i]); // 입력 키들
        n++;
    }

    inPlaceHeapSort(); // 힙 정렬 수행

    printArray(num);

    return 0;
}