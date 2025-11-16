#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int x) {
    if(root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

int count = 0, result = -1;

void kthMin(struct node *root, int k) {
    if(root == NULL) return;

    kthMin(root->left, k);
    count++;

    if(count == k) {
        result = root->data;
        return;
    }

    kthMin(root->right, k);
}

int main() {
    struct node *root = NULL;
    int n, x, k;

    printf("How many nodes? ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    kthMin(root, k);

    if(result != -1)
        printf("%dth Minimum = %d", k, result);
    else
        printf("k is larger than total nodes");

    return 0;
}
