#include <stdio.h>
#include <vector>
#include <algorithm>   // ★ 이거 없어서 컴파일 에러 났음

using namespace std;

vector<pair<int, pair<int, int>>> edges;

int parent[10001];

int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void mer(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        if (x < y) parent[y] = x;
        else parent[x] = y;
    }
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        edges.push_back({C, {A, B}});
    }

    sort(edges.begin(), edges.end());

    long long result = 0;

    for (int i = 0; i < E; i++)
    {
        if (find(edges[i].second.first) != find(edges[i].second.second))
        {
            mer(edges[i].second.first, edges[i].second.second);
            result += edges[i].first;
        }
    }

    printf("%lld\n", result);
    return 0;
}
