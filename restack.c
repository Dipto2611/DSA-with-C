#include <stdio.h>

#define N 5

int stack[N];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == N - 1;
}

void push() {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    int a;
    printf("Enter element: ");
    scanf("%d", &a);
    top++;
    stack[top] = a;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
    top--;
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i > -1; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("Enter operation:\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();
                    break;
            case 2: pop(); 
                    break;
            case 3: peek(); 
                    break;
            case 4: display(); 
                    break;
            case 5: printf("Exiting...\n");
                    printf("Final stack:\n");
                    display();
                    return 0;  // Exit the program
            default: printf("Invalid input\n");
        }
    }

    return 0;
}
