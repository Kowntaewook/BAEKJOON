#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len - 1;

    for(int i = 0; i < len; i++)
    {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int index = i + 1;
        while(index < len && name[index] == 'A')
            index++;
        
        move = min(move, i * 2 + len - index);
        move = min(move, (len - index) * 2 + i);
    }
    
    return answer + move;
}

int main()
{
    char name[20];
    scanf("%s", name);
    printf("%d\n", solution(name));
    return 0;
}