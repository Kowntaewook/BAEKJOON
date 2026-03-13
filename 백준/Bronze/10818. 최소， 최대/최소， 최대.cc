#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int number[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &number[i]);
    }

    int max = number[0];
    for (int i = 1; i < num; i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }

    int min = number[0];
    for (int i = 1; i < num; i++) {
        if (number[i] < min) {
            min = number[i];
        }
    }

    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}
