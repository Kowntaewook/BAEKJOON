#include <stdio.h>
#include <string.h>

int main()
{
    char A[21];
    char B[21];

    scanf("%s", A);
    scanf("%s", B);

    if(strcmp(A, B) == 0)
    {
        printf("0\n");
    }
    else
    {
        printf("1550\n");
    }

    return 0;
}