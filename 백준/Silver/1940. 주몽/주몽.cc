#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);
    vector<int> mater(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &mater[i]);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(mater[i] + mater[j] == m)
                    count++;
            }
        }
    
    printf("%d\n", count);
    return 0;
}