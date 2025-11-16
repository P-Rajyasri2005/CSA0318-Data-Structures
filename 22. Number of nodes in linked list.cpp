#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int choice = 1, count = 0;

    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Add another node? (1/0): ");
        scanf("%d", &choice);
    }

    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes = %d", count);
    return 0;
}
