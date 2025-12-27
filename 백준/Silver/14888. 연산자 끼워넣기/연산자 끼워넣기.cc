#include <stdio.h>

int N;
int A[12];
int op[4]; // +, -, *, /
int maxR = -1000000000;
int minR = 1000000000;

void dfs(int idx, int cur)
{
    if (idx == N)
    {
        if (cur > maxR) maxR = cur;
        if (cur < minR) minR = cur;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;

            if (i == 0)      
                dfs(idx + 1, cur + A[idx]);       // +
            else if (i == 1) 
                dfs(idx + 1, cur - A[idx]);       // -
            else if (i == 2) 
                dfs(idx + 1, cur * A[idx]);       // *
            else if (i == 3) // /
            {
                if (cur < 0)
                    dfs(idx + 1, -(-cur / A[idx]));
                else
                    dfs(idx + 1, cur / A[idx]);
            }

            op[i]++;
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < 4; i++)
        scanf("%d", &op[i]);

    dfs(1, A[0]); 

    printf("%d\n%d\n", maxR, minR);
    return 0;
}
