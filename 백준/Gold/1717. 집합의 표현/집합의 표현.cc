#include <stdio.h>

int parent[1000001];

int find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void uion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0)
        {
            uion(a, b);
        }
        else
        {
            if (find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}