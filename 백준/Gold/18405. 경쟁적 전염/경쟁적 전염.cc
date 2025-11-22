#include <stdio.h>
#include <queue>

using namespace std;

int n, k, S, X, Y;
int graph[201][201];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Virus {
    int type;
    int x;
    int y;
    int time;
};

queue<Virus> q;
queue<Virus> iniVirus[1001]; 

void bfs() {
    for (int t = 1; t <= k; t++) {
        while(!iniVirus[t].empty()) {
            q.push(iniVirus[t].front());
            iniVirus[t].pop();
        }
    }

    while(!q.empty()) {
        Virus cur = q.front();
        q.pop();

        if(cur.time == S) break;

        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(graph[nx][ny] == 0) {
                    graph[nx][ny] = cur.type;
                    q.push({cur.type, nx, ny, cur.time + 1});
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] != 0) {
                int t = graph[i][j];
                iniVirus[t].push({t, i, j, 0});
            }
        }
    }

    scanf("%d %d %d", &S, &X, &Y);

    bfs();

    printf("%d\n", graph[X-1][Y-1]);
    return 0;
}
