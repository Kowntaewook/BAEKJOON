#include <stdio.h>

int main() {
    int size = 100;      
    int paper_size = 10; 
    int n;               
    int x, y;
    int paper[100][100] = {0}; 
    int area = 0;

    scanf("%d", &n);  

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);  
        
        
        for (int r = y; r < y + paper_size; r++) {
            for (int c = x; c < x + paper_size; c++) {
                paper[r][c] = 1;
            }
        }
    }

    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (paper[i][j] == 1) {
                area++;
            }
        }
    }

    printf("%d\n", area);  
    return 0;
}
