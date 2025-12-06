#include <stdio.h>

int K;
int visitOrder[1023];      
int levelNodes[11][1023];   
int levelSize[11];          

void reconstruct(int left, int right, int depth) {
    if (left > right) 
        return;
    int mid = (left + right) / 2;
    levelNodes[depth][levelSize[depth]++] = visitOrder[mid];
    reconstruct(left, mid - 1, depth + 1);
    reconstruct(mid + 1, right, depth + 1);
}

int main() {
    int n, i, j;
    scanf("%d", &K);
    n = (1 << K) - 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &visitOrder[i]);
    }

    for (i = 0; i < 11; i++) levelSize[i] = 0;

    reconstruct(0, n - 1, 0);

    for (i = 0; i < K; i++) {
        for (j = 0; j < levelSize[i]; j++) {
            printf("%d ", levelNodes[i][j]);
        }
        printf("\n");
    }
    return 0;
} 
