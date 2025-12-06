#include <stdio.h>

#define MAX 100001
#define MAX_EDGES 200001

int head[MAX];
int next[MAX_EDGES];
int to[MAX_EDGES];
int edge_count;

int parent[MAX];
int visited[MAX];

void add_e(int u, int v) {
    to[edge_count] = v;
    next[edge_count] = head[u];
    head[u] = edge_count;
    edge_count++;
}

void dfs(int cur, int p) {
    visited[cur] = 1;
    parent[cur] = p;

    for (int i = head[cur]; i != -1; i = next[i]) {
        int nxt = to[i];
        if (!visited[nxt]) {
            dfs(nxt, cur);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
    edge_count = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_e(u, v);
        add_e(v, u);
    }

    dfs(1, 0);

    for (int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}
