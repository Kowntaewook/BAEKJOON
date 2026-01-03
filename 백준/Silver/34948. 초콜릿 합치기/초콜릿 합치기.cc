#include <stdio.h>
#include <stdlib.h>

typedef struct {
int h;
int w;
} Chocolate;

int compareHeight(const void *a, const void *b)
{
    const Chocolate *c1 = (const Chocolate *)a;
    const Chocolate *c2 = (const Chocolate *)b;
    return c2->h - c1->h;
}


int main()
{
int n;
scanf("%d", &n);

Chocolate *choco = (Chocolate *)malloc(sizeof(Chocolate) * n);
if (choco == NULL)
    return 0;

for (int i = 0; i < n; i++)
    scanf("%d", &choco[i].h);

for (int i = 0; i < n; i++)
    scanf("%d", &choco[i].w);

qsort(choco, n, sizeof(Chocolate), compareHeight);

long long widthSum = 0;
long long result = 0;

for (int i = 0; i < n; i++)
{
    widthSum += choco[i].w;
    long long temp = (long long)choco[i].h * widthSum;
    if (temp > result)
        result = temp;
}

printf("%lld\n", result);

free(choco);
return 0;


}