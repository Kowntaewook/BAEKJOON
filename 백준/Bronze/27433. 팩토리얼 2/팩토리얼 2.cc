#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  
    
    long long result = 1; 
    for (int i = 2; i <= N; i++) {
        result *= i;  
    }
    
    printf("%lld\n", result);  
    return 0;
}
