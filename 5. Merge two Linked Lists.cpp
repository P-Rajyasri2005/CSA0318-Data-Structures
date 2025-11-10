#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    struct Node *head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    printf("Merged Linked List: ");
    display(head1);
    return 0;
}
