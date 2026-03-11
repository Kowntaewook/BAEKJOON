#include <stdio.h>
int main(){
    int num,num2;
    scanf("%d %d", &num,&num2);

    int number[num];
    for(int i=0; i<num; i++){
        scanf("%d",&number[i]);
    }
    for(int i=0; i<num; i++){
        if(number[i]<num2){
            printf("%d ", number[i]);
        }
    }


    return 0;
}