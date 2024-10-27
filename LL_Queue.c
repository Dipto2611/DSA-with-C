#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;

}node;

/// here 0 is NULL only 
node* front=NULL; //most imp take the struct part not the int of something
node* rear=NULL;

void enqueue(int val){
    node* newnode;
    newnode=(node*)malloc(sizeof(node));

    newnode->data=val;  //define a node [data|next]
    newnode->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=newnode; //all pointing the same node 
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

/// here FIFO is used so temp will point the Front only as for deletion.
void dequeue(){
    node*temp;
    temp=front; //front ka value is assigned to temp not the vice versa!!
     
    if(front==NULL && rear==NULL){
        printf("Queue is empty.");
    }
    else{
        int delEl=temp->data;
        front=front->next; //inc front not the temp as temp will hold the 1st val to be deleted
        free(temp); //then go off the temp part

        printf("Deleted element is %d",delEl);
    }

}

void peek(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty.");
    }
    else
    {
        printf("The Top element is %d",front->data); //as frnt se del hona h.
    }
    
}

void display(){
     if(front==NULL && rear==NULL){
        printf("Queue is empty.");
    }
    else{
        node*temp;
        temp=front;
        while(temp!=NULL){
            printf("%d -> ",temp->data); //remember "data" has to be printed not then next part nigga
            temp=temp->next; //it has to be in while loop otheewise its gonna be in loop
        }
        //p->next=newnode;  (its for linking only dont copy to QLL)
    }

}

int main() {
    int choice;
    int val;

    while (1) {
        printf("\nOperations you can perform:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter the element: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2: 
                dequeue();
                break;
            case 3: 
                peek(); // Call the peek function
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