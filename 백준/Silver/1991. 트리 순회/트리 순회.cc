#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
};


typedef struct node Node;
Node *tree[26];
char data[26];
char preoder[26];
char inoder[26];
char postoder[26];

int pre_cnt = 0;
int in_cnt = 0;
int post_cnt = 0;

void preorder(Node *root)
{
    if(root != NULL)
    {
        preoder[pre_cnt++] = root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        inoder[in_cnt++] = root->data;
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        postoder[post_cnt++] = root->data;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char root, left, right;
        getchar();
        scanf("%c %c %c", &root, &left, &right);
        data[root - 'A'] = root;
        if(left != '.')
        {
            data[left - 'A'] = left;
            if(tree[root - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = root;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[root - 'A'] = newNode;
            }
            if(tree[left - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = left;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[left - 'A'] = newNode;
            }
            tree[root - 'A']->left = tree[left - 'A'];
        }
        if(right != '.')
        {
            data[right - 'A'] = right;
            if(tree[root - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = root;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[root - 'A'] = newNode;
            }
            if(tree[right - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = right;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[right - 'A'] = newNode;
            }
            tree[root - 'A']->right = tree[right - 'A'];
        }
    }
    preorder(tree['A' - 'A']);
    inorder(tree['A' - 'A']);
    postorder(tree['A' - 'A']);
    printf("%s\n", preoder);
    printf("%s\n", inoder);
    printf("%s\n", postoder);
    return 0;
}