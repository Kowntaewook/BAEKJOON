#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    int len = strlen(number);
    int result_len = len - k;
    char* answer = (char*)malloc(result_len + 1);
    int idx = 0;
    int ans_idx = 0;

    for(int i = 0; i < result_len; i++)
    {
        char max = '0' - 1;
        int max_idx = idx;
        
        for(int j = idx; j <= i + k; j++)
        {
            if(number[j] > max)
            {
                max = number[j];
                max_idx = j;
            }
        }
        
        answer[ans_idx++] = max;
        idx = max_idx + 1;
    }
    
    answer[result_len] = '\0';
    return answer;
}

int main()
{
    char number[1000001];
    int k;
    scanf("%s %d", number, &k);
    char* answer = solution(number, k);
    printf("%s\n", answer);
    free(answer);
    return 0;
}