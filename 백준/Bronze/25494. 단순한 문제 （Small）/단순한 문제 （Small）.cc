#include <stdio.h>
int main(void) {
    int t; // 테스트케이스의 개수
    scanf("%d", &t);

    while (t--) { // t번 반복

        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int ans = 0; // 개수를 저장할 변수

        for (int x = 1; x <= a; x++) // x를 1부터 a까지 반복
            for (int y = 1; y <= b; y++) // y를 1부터 b까지 반복
                for (int z = 1; z <= c; z++) // z를 1부터 c까지 반복
                    if (x % y == y % z && y % z == z % x) // 만약 4번째 조건을 만족한다면
                        ans++; // 개수 카운팅하기

        printf("%d\n", ans); // 정답 출력
    }
}