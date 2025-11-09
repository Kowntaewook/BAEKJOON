#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[8][8];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = 0;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void bfs()
{
    int afterMap[8][8];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            afterMap[i][j] = map[i][j];
        }
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        q.push(make_pair(v[i].first, v[i].second));
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (afterMap[nx][ny] == 0)
                    {
                        afterMap[nx][ny] = 2;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (afterMap[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    
   ans = max(ans, cnt);
}

void wall(int cnt)
{
    if(cnt == 3)
    {
        bfs();
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 0)
            {
                map[i][j] = 1;
                wall(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2)
            {
                v.push_back(make_pair(i, j));
            }
        }
    }
    
    wall(0);
    printf("%d\n", ans);
    
    return 0;
}