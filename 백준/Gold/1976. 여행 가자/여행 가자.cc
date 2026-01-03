#include <stdio.h>
#include <vector>
using namespace std;

int parent[201];

int find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void uionn(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp == 1)
                uionn(i, j);
        }
    }

    vector<int> plan(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &plan[i]);
    }

    
    for (int i = 0; i < m - 1; i++) {
        if (find(plan[i]) != find(plan[i + 1])) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
