#include <stdio.h>

int preorder[10001];
int n = 0;

void postOrder(int start, int end)
{
    if (start > end)
        return;

    int root = preorder[start];
    int idx = start + 1;

    
    while (idx <= end && preorder[idx] < root)
        idx++;

    
    postOrder(start + 1, idx - 1);
    postOrder(idx, end);
    printf("%d\n", root);
}

int main()
{
    while (scanf("%d", &preorder[n]) != EOF)
        n++;

    postOrder(0, n - 1);
    return 0;
}
