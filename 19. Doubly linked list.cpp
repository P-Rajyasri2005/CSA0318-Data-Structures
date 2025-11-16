#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void insert_end() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL)
        head = newnode;
    else {
        struct node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display_forward() {
    struct node *temp = head;
    if(temp == NULL) {
        printf("List Empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_reverse() {
    if(head == NULL) {
        printf("List Empty\n");
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Insert at End\n2.Display Forward\n3.Display Reverse\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert_end(); break;
            case 2: display_forward(); break;
            case 3: display_reverse(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
