#include <stdio.h>

int countF(char b[8][9]) {
    int c = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && b[i][j] == 'F') { 
                c++;
            }
        }
    }
    return c;
}

int main() {
    char b[8][9];
    for (int i = 0; i < 8; i++) {
        scanf("%s", b[i]);
    }
    
    printf("%d\n", countF(b));
    return 0;
}
