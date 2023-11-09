#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 100

int H[MAX_HEAP_SIZE]; // ���� �迭�� �� ����
int n = 0; // ���� �� Ű ����

void downHeap(int i) {	// 3������ ������
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
    for (int i = n / 2; i >= 1; i--) {	// �� ����
        downHeap(i);
    }

    for (int i = n; i > 1; i--) {   // root ��带 �ϳ��� ���� ����
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
    int num; // Ű ����

    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        scanf("%d", &H[i]); // �Է� Ű��
        n++;
    }

    inPlaceHeapSort(); // �� ���� ����

    printArray(num);

    return 0;
}