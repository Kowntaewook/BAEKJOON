#include <stdio.h>

int main() {
    char words[5][16] = {0};
    int maxlength = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%s", words[i]);
        int length = 0;
        while (words[i][length] != '\0') {
            length++;
        }
        if (length > maxlength) {
            maxlength = length;
        }
    }

    for (int j = 0; j < maxlength; j++) {
        for (int i = 0; i < 5; i++) {
            if (words[i][j] != '\0') {
                printf("%c", words[i][j]);
            }
        }
    }
    
    printf("\n");
    return 0;
}

