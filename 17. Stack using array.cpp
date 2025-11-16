#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE], top = -1;

void push() {
    if(top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    int x;
    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped = %d\n", stack[top--]);
}

void display() {
    if(top == -1) {
        printf("Stack Empty\n");
        return;
    }
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
