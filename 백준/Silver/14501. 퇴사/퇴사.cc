#include <stdio.h>

int n;
int t[16];
int p[16];
int dp[16];

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d %d", &t[i], &p[i]);

    for(int i = n; i >= 1; i--)
    {
        if(i + t[i] - 1 <= n)
            dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
        else
            dp[i] = dp[i + 1];
    }

    printf("%d\n", dp[1]);
    return 0;
}