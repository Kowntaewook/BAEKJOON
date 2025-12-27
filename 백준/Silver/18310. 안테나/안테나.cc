#include <stdio.h>

int N;
int A[200000];
int ans;
long long minD = 1000000000000LL;

int abs(int x)
{
    if(x < 0)
        return -x;
    return x;
}

int compare(int a, int b)
{
    return a - b;
}

void qsort(int arr[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    while(i <= j)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if(left < j)
        qsort(arr, left, j);
    if(i < right)
        qsort(arr, i, right);
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // 정렬
    qsort(A, 0, N - 1);
    ans = A[(N - 1) / 2];
    printf("%d\n", ans);
    return 0;
}