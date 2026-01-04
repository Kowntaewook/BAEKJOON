#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> v;

int parent[100001];

int find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void mer(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        if(x < y) parent[y] = x;
        else parent[x] = y;
    
    }
}


int main()
{
    int n, m, a, b, c, i, sum = 0, max = 0;
    
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end());
    for(i = 0; i < m; i++)
    {
        if(find(v[i].second.first) != find(v[i].second.second))
        {
            mer(v[i].second.first, v[i].second.second);
            sum += v[i].first;
            if(v[i].first > max) max = v[i].first;
        }
    }

    printf("%d\n", sum - max);

    return 0;
}