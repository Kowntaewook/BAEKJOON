#include <stdio.h>
#include <vector>

using namespace std;

const long long INF = 4e18;

int n, m;
vector<pair<int, int>> graph[501];
long long dist[501];
bool neg = false;

void bellman_ford(int start)
{
    dist[start] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int u = 1; u <= n; u++)
        {
            if(dist[u] == INF) continue;

            for(size_t j = 0; j < graph[u].size(); j++)
            {
                int v = graph[u][j].first;
                int cost = graph[u][j].second;

                if(dist[v] > dist[u] + cost)
                {
                    dist[v] = dist[u] + cost;

                    if(i == n)
                    {
                        neg = true;
                        return;   
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }

    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    bellman_ford(1);

    if(neg)
    {
        printf("-1\n");
        return 0;
    }

    for(int i = 2; i <= n; i++)
    {
        if(dist[i] == INF)
            printf("-1\n");
        else
            printf("%lld\n", dist[i]);
    }

    return 0;
}
