#include <stdio.h>


int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}


void f(long M, long N) {
    long sum = 0, min = 0, found = 0;

    for (long i = M; i <= N; i++) {
        if (is_prime(i)) {
            sum += i;
            if (!found) { 
                min = i;
                found = 1;
            }
        }
    }

    if (found) {
        printf("%ld\n%ld\n", sum, min);
    } else {
        printf("-1\n");
    }
}

int main() {
    long M, N;
    scanf("%ld %ld", &M, &N);
    f(M, N);
    return 0;
}

