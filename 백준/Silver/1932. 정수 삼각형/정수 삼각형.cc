#include <stdio.h>

int triangle[501][501];
int dp[501][501];
int n;
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
    {
        for(int j = 1; j <= i; j++)
        {
            scanf("%d", &triangle[i][j]);
        }
    }

    dp[1][1] = triangle[1][1];

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 1)
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if(j == i)
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    int result = 0;
    for(int i = 1; i <= n; i++)
    {
        result = max(result, dp[n][i]);
    }
    printf("%d\n", result);
    return 0;
}