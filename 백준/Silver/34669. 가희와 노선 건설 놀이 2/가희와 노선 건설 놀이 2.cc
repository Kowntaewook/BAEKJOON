#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        long long c, k;
        scanf("%lld %lld", &c, &k);
        printf("%lld %lld\n", c * k, c / k);
    }
    return 0;
}