#include <stdio.h>

int main() {
    int N, M, i, j;
    scanf("%d %d", &N, &M);

    int arr[100];
    for (int k = 0; k < N; k++) {
        arr[k] = k + 1;
    }

    for (int k = 0; k < M; k++) {
        scanf("%d %d", &i, &j);
        if (i != j) { // 같은 번호일 경우 스왑 불필요
            arr[i - 1] ^= arr[j - 1];
            arr[j - 1] ^= arr[i - 1];
            arr[i - 1] ^= arr[j - 1];
        }
    }

    for (int k = 0; k < N; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}
