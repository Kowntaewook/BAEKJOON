#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        int M;
        scanf("%d", &M);
        int a = M + 1;
        int k = (a + 49) / 50;
        int time_min = 366 + 12 * (k - 1);
        if(time_min >= 1440) {
            printf("-1\n");
        } else {
            int hh = time_min / 60;
            int mm = time_min % 60;
            printf("%02d:%02d\n", hh, mm);
        }
    }
    return 0;
}