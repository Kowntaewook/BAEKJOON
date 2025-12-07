#include <stdio.h>
#include <vector>
using namespace std;
vector<int> inorder;
vector<int> postorder;

void preorder(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe)
        return;
    int root = postorder[pe];
    printf("%d ", root);
    int idx = is;
    while (inorder[idx] != root)
        idx++;
    int len = idx - is;
    preorder(is, idx - 1, ps, ps + len - 1);
    preorder(idx + 1, ie, ps + len, pe - 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        inorder.push_back(temp);
    }

    
    for(int j = 0; j < n; j++)
    {
        int temp;
        scanf("%d", &temp);
        postorder.push_back(temp);
    }
    preorder(0, n - 1, 0, n - 1);
    printf("\n");

    return 0;
}