#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> graph[300001];
int dist[300001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if(dist[next] == -1)
            {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}


int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &x);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
    {
        dist[i] = -1;
    }
    bfs(x);
    
    bool found = false;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == k)
        {
            printf("%d\n", i);
            found = true;
        }
    }
    if(!found)
    {
        printf("-1\n");
    }
    return 0;
}