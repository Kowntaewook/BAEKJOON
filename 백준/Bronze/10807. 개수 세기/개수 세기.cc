#include <stdio.h>
int main(){
    int num;
    scanf("%d", &num);

    int number[num];
    for(int i=0; i<num; i++){
        scanf("%d", &number[i]);
    }
    int num2;
    scanf("%d", &num2);

    int count=0;
    for(int i=0; i<num; i++){
        if(number[i]==num2){
            count++;
        }
    }
    printf("%d\n", count);


    return 0;
}
