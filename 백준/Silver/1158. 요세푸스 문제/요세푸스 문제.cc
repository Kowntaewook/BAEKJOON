#include <stdio.h>
#include <queue>

using namespace std;

// 요세푸스 문제 해결용 구조체

struct process
{
    int index;
    int value;
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    queue<process> q;

    for(int i = 1; i <= n; i++)
    {
        q.push({i, i }); // index는 사람 번호, value는 사람 순서
    }

    printf("<");
    int count = 0;

    while(q.size() > 0)
    {
        count++;
        process p = q.front();
        q.pop();

        if(count == k)
        {
            printf("%d", p.index);
            if(q.size() > 0)
            {
                printf(", ");
            }
            count = 0;
        }
        else
        {
            q.push(p);
        }
    }
    printf(">\n");
    return 0;
}