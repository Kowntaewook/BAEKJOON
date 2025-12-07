#include <stdio.h>

int parent[1001];

int find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
        parent[y] = x;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            
            if(find(a) != find(b))
            {
                unite(a, b);
                cnt++;
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}