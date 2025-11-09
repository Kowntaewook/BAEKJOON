#include <stdio.h>
#include <string.h>

int main() {
    char N[9]; 
    scanf("%s", N);

    int length = strlen(N);
    int half = length / 2;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < half; i++) {
        sum1 += N[i] - '0';
    }
    for (int i = half; i < length; i++) {
        sum2 += N[i] - '0';
    }

    if (sum1 == sum2)
        printf("LUCKY");
    else
        printf("READY");

    return 0;
}
