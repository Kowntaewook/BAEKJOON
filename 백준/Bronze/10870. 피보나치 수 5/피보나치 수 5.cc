#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 
    
    int fib[21] = {0, 1};  
    
    
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("%d\n", fib[n]);  
    return 0;
}
