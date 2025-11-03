#include <stdio.h>

int main() {
    int num, remainder;
    int remainders[42] = {0};
    int count = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);
        remainder = num % 42;
        remainders[remainder] = 1;
    }

    for (int i = 0; i < 42; i++) {
        if (remainders[i]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}