#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if(x == -1) return NULL;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    printf("Left child of %d:\n", x);
    newnode->left = create();

    printf("Right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

void inorder(struct node *root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node *root = create();

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
