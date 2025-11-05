#include <stdio.h>
int main(){
    int a;

    printf("");
    scanf("%d", &a);

    for(int i=0; i<=a; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        for(int b=a-i; b > 0; b--){
                printf("*");
        }
        printf("\n");
    }
    return 0;
}
