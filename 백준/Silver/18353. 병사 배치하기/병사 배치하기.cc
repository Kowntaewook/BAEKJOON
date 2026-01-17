#include <stdio.h>
#include <vector>

using namespace std;
int n;
int soldiers[2001];
int dp[2001];

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &soldiers[i]);
    }

    int result = 0;

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(soldiers[j] > soldiers[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    printf("%d\n", n - result);
    return 0;
}