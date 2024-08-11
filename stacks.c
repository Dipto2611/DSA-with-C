///Main code: 
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
    top+=1;
    stack[top]=a;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n",stack[top]);
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
        for (int i = top; i >-1; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, exit;

    do {
        printf("Enter operation:\n1: Push\n2: Pop\n3: Peek\n4: Display\nChoose: ");
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
            default: printf("Invalid input\n"); 
                
        }

        printf("Continue? YES(1) or NO(0): ");
        scanf("%d", &exit);
    } while (exit !=0 );

    printf("Final stack:\n");
    display();

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #define N 5

// int stack [5];
// int top = -1;

// int isEmpty(){
//     if (top==-1)///as no elements here so outside of box
//     printf("Its Underflow");
  
// }
// int isFull(){
//     if (top>N-1) ///as here index is from 0-n and len is 1-n so N-1
//     printf("Its Overflow");
// }

// void push(){
//     int a;
//     printf("Enter the elements:");
//     scanf("%d",&a);
//     top+=1;
//     stack[top]=a;
// }

// int pop(){
//     printf("%d",stack[top]);
//     top--;

// }
// int peek(){
//     // return the top element to main()
//     printf("%d", stack[top]);    
// }

// int display(){
//     for(int i=top;i>-1;i--){
//          printf("%d\n",stack[i]);
//     }
   
// }

// int main(){
//     int choose;
//     int exit;    

//     do{
//         printf("Enter the ops you want:- \n1:Push \n2:Pop \n3:Peek \n4:Display \t" );
//         scanf("%d",&choose);

//         switch(choose){
//             case 1:
//                 push();
//                 break;
//             case 2:
//                 pop();
//                 break;
//             case 3:
//                 peek();
//                 break;
//             case 4:
//                 display();
//                 break;
//             default:
//                 printf("Invalid Input");
//                 break;
//         }
//         printf("Do you want to continue:YES(1) or NO(0):");
//         scanf("%d",&exit);
//     }
//     while (exit!=0);
    
//     printf("The Final stack is :\n");
//     display();
    

// }
