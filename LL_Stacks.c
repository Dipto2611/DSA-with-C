#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* top = NULL; //its imp for top to be in stck

void push(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = top;
    top = newnode; // top points to the new node
    printf("Pushed element: %d\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        node* temp = top;
        int delEl = temp->data;
        top = top->next;
        free(temp);

        printf("Popped element: %d\n", delEl);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        node* temp = top;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    int val;

    while (1) {
        printf("\nOperations you can perform:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter the element: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                peek();
                break;
            case 4: 
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid input entered\n");
                break;
        }
    }
    return 0;
}
