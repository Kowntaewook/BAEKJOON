#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        char map[N][M + 1];

        for(int j = 0; j < N; j++)
        {
            scanf("%s", map[j]);
        }

        int empty = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(map[i][j] == '.')
                {
                    empty++;
                }
            }
        }

        if (empty % 2 == 1)
            printf("sewon\n");
        else
            printf("pizza\n");
    }

    return 0;
}