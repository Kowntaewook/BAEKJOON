#include <stdio.h>
#include <vector> 
#include <queue>

using namespace std;
#define INF 1e9

struct Edge
{
    int to;
    int cost;
};

int n,m,a,b;
int money[51];
vector<Edge> adj[51];
long long dist[51];
bool in_nega_C[51];
bool visited[51];

void bellman()
{
    dist[a] = money[a];
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(auto &edge : adj[j])
            {
                if(dist[j] == -INF)
                    continue;
                if(dist[edge.to] < dist[j] - edge.cost + money[edge.to])
                {
                    dist[edge.to] = dist[j] - edge.cost + money[edge.to];
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &a, &b, &m);

    for(int i = 0; i < m; i++)
    {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back({v,c});
    }

    for(int i = 0; i < n; i++)
        scanf("%d", &money[i]);
        for(int i = 0; i < n; i++)
            dist[i] = -INF;
    bellman();

    for(int i = 0; i < n; i++)
    {
        for(auto &edge : adj[i])
        {
            if(dist[i] == -INF)
                continue;
            if(dist[edge.to] < dist[i] - edge.cost + money[edge.to])
            {
                in_nega_C[edge.to] = true;
            }
        }
    }
    queue<int> Q;
    for(int i = 0; i < n; i++)
    {
        if(in_nega_C[i])
        {
            Q.push(i);
            visited[i] = true;
        }
        else
            visited[i] = false;
    }

    while(!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        for(auto &edge : adj[curr])
        {
            if(!visited[edge.to])
            {
                visited[edge.to] = true;
                Q.push(edge.to);
            }
        }
    }

    if(visited[b])
        printf("Gee\n");
    else if(dist[b] == -INF)
        printf("gg\n");
    else
        printf("%lld\n", dist[b]);

    return 0;
}