#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

struct Edge {
    int u, v;
    ll c;
};

int cmp(const void *a, const void *b) {
    struct Edge *aa = (struct Edge *)a;
    struct Edge *bb = (struct Edge *)b;
    if (aa->u != bb->u) return aa->u - bb->u;
    return aa->v - bb->v;
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    struct Edge *edges = (struct Edge *)malloc(sizeof(struct Edge) * M);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if (a < b) {
            edges[i].u = a;
            edges[i].v = b;
        } else {
            edges[i].u = b;
            edges[i].v = a;
        }
        edges[i].c = c;
    }

    qsort(edges, M, sizeof(struct Edge), cmp);

    int cnt = 0;
    struct Edge *uniq = (struct Edge *)malloc(sizeof(struct Edge) * M);
    for (int i = 0; i < M; ) {
        int j = i;
        ll minc = edges[i].c;
        while (j < M && edges[j].u == edges[i].u && edges[j].v == edges[i].v) {
            if (edges[j].c < minc) minc = edges[j].c;
            j++;
        }
        uniq[cnt].u = edges[i].u;
        uniq[cnt].v = edges[i].v;
        uniq[cnt].c = minc;
        cnt++;
        i = j;
    }

    struct Edge key;
    for (int i = 0; i < Q; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        int u, v;
        if (s < e) {
            u = s;
            v = e;
        } else {
            u = e;
            v = s;
        }
        key.u = u;
        key.v = v;
        struct Edge *res = (struct Edge *)bsearch(&key, uniq, cnt, sizeof(struct Edge), cmp);
        if (res == NULL) {
            printf("-1\n");
        } else {
            printf("%lld\n", res->c);
        }
    }

    free(edges);
    free(uniq);
    return 0;
}