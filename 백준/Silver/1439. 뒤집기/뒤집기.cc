#include <stdio.h>
#include <string.h>

int main() {
    char S[1000001];
    scanf("%s", S);
    int len = strlen(S);

    int c0 = 0;
    int c1 = 0;

    if (S[0] == '0') 
        c0 = 1;
    else 
        c1 = 1;

    for (int i = 1; i < len; i++) {
        if (S[i] != S[i - 1]) {
            if (S[i] == '0') 
                c0++;
            else 
                c1++;
        }
    }

    int ans;
    if (c0 < c1)
        ans = c0;
    else
        ans = c1;
    printf("%d\n", ans);

    return 0;
}
