#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n,p;
char s[1000001];
int required[4];
int current[4];
int valid_count = 0;
int answer = 0;

void add_char(char C)
{
    for(int i = 0; i < 4; i++)
    {
        if(C == "ACGT"[i])
        {
            current[i]++;
            if(current[i] == required[i])
                valid_count++;
            break;
        }
        else
            continue;
    }
}

int main()
{
    scanf("%d %d", &n, &p);
    scanf("%s", s);
    
    for(int i = 0; i < 4; i++)
        scanf("%d", &required[i]);

    for(int i = 0; i < 4; i++)
    {
        if(required[i] == 0)
            valid_count++;
    }

    for(int i = 0; i < p; i++)
        add_char(s[i]);
    
    if(valid_count == 4)
        answer++;
    for(int i = p; i < n; i++)
    {
        add_char(s[i]);
        char removed_char = s[i - p];
        for(int j = 0; j < 4; j++)
        {
            if(removed_char == "ACGT"[j])
            {
                if(current[j] == required[j])
                    valid_count--;
                current[j]--;
                break;
            }
            else
                continue;
        }
        if(valid_count == 4)
            answer++;
    }
    printf("%d\n", answer);
    return 0;
}