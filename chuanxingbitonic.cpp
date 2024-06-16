#include <iostream>
#include <stdio.h>
#include <ctime>
#define N 16 // 双调序列的长度

void printArray(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bitonicSplit(int arr[], int low, int cnt, int dir, int s1[], int s2[]) {
    if (cnt > 1) {
        int k = cnt / 2;

        // 递归调用分裂左边
        bitonicSplit(arr, low, k, 1, s1, s2);
        // 递归调用分裂右边
        bitonicSplit(arr, low + k, k, 0, s1, s2);

        // 合并两个双调序列
        for (int i = low; i < low + k; i++) {
            if (dir == 1) {
                s1[i] = (arr[i] < arr[i + k]) ? arr[i] : arr[i + k];
                s2[i] = (arr[i] > arr[i + k]) ? arr[i] : arr[i + k];
            } else {
                s1[i] = (arr[i] > arr[i + k]) ? arr[i] : arr[i + k];
                s2[i] = (arr[i] < arr[i + k]) ? arr[i] : arr[i + k];
            }
        }
    }
}

int main() {
    int arr[N] = {0,1,2,3,4,5,6,7,8,6,5,4,3,2,1,0};
    int s1[N/2], s2[N/2]; // 两个子序列的数组
	clock_t start = clock();
    printf("Original array: ");
    printArray(arr, 0, N);

    bitonicSplit(arr, 0, N, 1, s1, s2);

    printf("Split arrays:\n");
    printf("First part (s1): ");
    printArray(s1, 0, N/2);
    printf("Second part (s2): ");
    printArray(s2, 0, N/2);
	clock_t end = clock();
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "Time taken: " << elapsed_time << " milliseconds" << std::endl;
    return 0;
}

