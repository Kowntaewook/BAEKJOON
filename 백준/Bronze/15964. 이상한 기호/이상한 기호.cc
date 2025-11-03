#include <stdio.h>


long f(long A, long B) {
    return (A + B) * (A - B);
}

int main() {
    long A, B;

    
    scanf("%ld %ld", &A, &B);

    
    long result = f(A, B);

    
    printf("%ld\n", result);

    return 0;
}