#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            printf(" ");
        }
        printf("*");
        if (i > 1) {
            for (int j = 1; j <= 2 * (i - 1) - 1; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
