#include <stdio.h>

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    
    int arr[100][100], temp[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for (int r = 0; r < R; r++) {
        int op;
        scanf("%d", &op);
        
        if (op == 1) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[N - 1 - i][j] = arr[i][j];
                }
            }
        } else if (op == 2) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[i][M - 1 - j] = arr[i][j];
                }
            }
        } else if (op == 3) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[j][N - 1 - i] = arr[i][j];
                }
            }
            int t = N;
            N = M;
            M = t;
        } else if (op == 4) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    temp[M - 1 - j][i] = arr[i][j];
                }
            }
            int t = N;
            N = M;
            M = t;
        } else if (op == 5) {
            int h = N / 2, w = M / 2;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    temp[i][j + w] = arr[i][j];
                    temp[i + h][j + w] = arr[i][j + w];
                    temp[i + h][j] = arr[i + h][j + w];
                    temp[i][j] = arr[i + h][j];
                }
            }
        } else if (op == 6) {
            int h = N / 2, w = M / 2;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    temp[i + h][j] = arr[i][j];
                    temp[i][j] = arr[i][j + w];
                    temp[i][j + w] = arr[i + h][j + w];
                    temp[i + h][j + w] = arr[i + h][j];
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = temp[i][j];
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
