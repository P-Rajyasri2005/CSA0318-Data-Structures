#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nMinimum: %d", findMin(root));
    printf("\nMaximum: %d", findMax(root));

    int key = 60;
    struct node *found = search(root, key);
    if (found)
        printf("\nElement %d found in BST", key);
    else
        printf("\nElement %d not found", key);

    return 0;
}
