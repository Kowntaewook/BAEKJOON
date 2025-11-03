#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char map[101][101];
char colorblind_map[101][101];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void bfs(int x, int y, char target, int n, char board[101][101], bool visited[101][101]) {
    queue<int> q;
    q.push(x);
    q.push(y);
    visited[x][y] = true;

    while (!q.empty()) {
        int curx = q.front(); q.pop();
        int cury = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;
            if (board[nx][ny] != target)
                continue;

            visited[nx][ny] = true;
            q.push(nx);
            q.push(ny);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'G') {
                colorblind_map[i][j] = 'R';
            } else {
                colorblind_map[i][j] = map[i][j];
            }
        }
    }

    int normal_count = 0, colorblind_count = 0;

    // 일반 시야용 BFS
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, map[i][j], n, map, visited);
                normal_count++;
            }
        }
    }

    // 색약 시야용 BFS
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, colorblind_map[i][j], n, colorblind_map, visited);
                colorblind_count++;
            }
        }
    }

    printf("%d %d\n", normal_count, colorblind_count);
    return 0;
}
