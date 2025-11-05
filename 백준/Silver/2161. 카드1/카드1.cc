#include <stdio.h>
#include <queue>

using namespace std;

queue<int> q;

/*예제 입력 1 
7
예제 출력 1 
1 3 5 7 4 2 6 8*/

// 계산 함수

void process(int n)
{
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while(q.size() > 1)
    {
        printf("%d ", q.front());
        q.pop();
        int front = q.front();
        q.pop();
        q.push(front);
    }
    printf("%d\n", q.front());
    q.pop();
}

int main()
{
    int n;
    scanf("%d", &n);
    process(n);
    return 0;
}