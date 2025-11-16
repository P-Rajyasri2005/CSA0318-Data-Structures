#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else {
        struct node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Insert\n2.Display\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
