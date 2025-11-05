#include <stdio.h>

int f(int a, int b, int c, int d, int e) {
    return ((a * a) + (b * b) + (c * c) + (d * d) + (e * e)) % 10;
}

int main() {
    int a, b, c, d, e;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int result = f(a, b, c, d, e);
    printf("%d\n", result);
    
    return 0;
}
