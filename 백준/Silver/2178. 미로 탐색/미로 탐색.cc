#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[201][201]; 
int dist[201][201]; 

void bfs(int n, int m, vector<vector<int>>& maze) 
{
    queue<int> q;
    q.push(0); 
    visited[0][0] = true;
    dist[0][0] = 1;

    while(!q.empty())
    {
        int index = q.front(); q.pop();
        int x = index / m;
        int y = index % m;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(maze[nx][ny] == 0 || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(nx * m + ny); 
        }
    }

    printf("%d\n", dist[n - 1][m - 1]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> maze(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs(n, m, maze);
    return 0;
}
