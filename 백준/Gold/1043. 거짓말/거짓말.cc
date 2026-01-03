#include <stdio.h>
#include <vector>

using namespace std;

int parent[51];

int find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void uionn(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int t;
    scanf("%d", &t);

    vector<int> truth;
    for (int i = 0; i < t; i++)
    {
        int x;
        scanf("%d", &x);
        truth.push_back(x);
    }

    vector<vector<int>> parties(m);
    
    for (int i = 0; i < m; i++)
    {
        int p;
        scanf("%d", &p);

        for (int j = 0; j < p; j++)
        {
            int x;
            scanf("%d", &x);
            parties[i].push_back(x);

            if (j > 0)
                uionn(parties[i][0], x);
        }
    }

    int result = 0;

    
    for (int i = 0; i < m; i++)
    {
        bool canLie = true;

        for (int j = 0; j < parties[i].size(); j++)
        {
            int person = parties[i][j];

            for (int k = 0; k < truth.size(); k++)
            {
                if (find(person) == find(truth[k]))
                {
                    canLie = false;
                    break;
                }
            }

            if (!canLie)
                break;
        }

        if (canLie)
            result++;
    }

    printf("%d\n", result);
    return 0;
}
