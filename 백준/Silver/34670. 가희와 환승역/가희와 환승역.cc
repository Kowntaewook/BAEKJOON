#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int Q;
    scanf("%d", &Q);

    for(int q = 0; q < Q; q++)
    {
        int n;
        scanf("%d", &n);

        char stations[27270][20];
        for(int i = 0; i < n; i++)
        {
            scanf("%s", stations[i]);
        }

        if(n < 2)
        {
            printf("NO\n");
            continue;
        }

        char first_num[3];
        bool same = true;
        bool has_dash = false;

        for(int i = 0; i < n; i++)
        {
            char* s = stations[i];
            int len = strlen(s);
            char num[3];

            if(strchr(s, '-'))
            {
                has_dash = true;
                char* dash = strchr(s, '-');
                strcpy(num, dash + 1);
            }
            else
            {
                strcpy(num, s + len - 2);
            }

            if(i == 0)
            {
                strcpy(first_num, num);
            }
            else
            {
                if(strcmp(first_num, num) != 0)
                {
                    same = false;
                }
            }
        }

        if(has_dash || !same)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}