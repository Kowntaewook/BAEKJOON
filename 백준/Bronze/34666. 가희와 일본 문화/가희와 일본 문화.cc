#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        int L, A, B, C;
        scanf("%d %d %d %d", &L, &A, &B, &C);
        if(L != 1 && L != 2) {
            printf("NO\n");
            continue;
        }
        if(C < 50) {
            printf("NO\n");
            continue;
        }
        int min_total = (L == 1) ? 100 : 90;
        int min_pass = 19;
        int count31 = 0;
        if(min_total > 3 * A) count31++;
        if(min_total > 3 * B) count31++;
        int count32 = 0;
        if(A <= min_pass + 2) count32++;
        if(B <= min_pass + 2) count32++;
        if(count31 >= 2 || count32 >= 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}