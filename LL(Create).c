//to create a linked list from root

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;           //as per blocks .. [data|address * next]
    struct node* next; //------^
}node;

node* head=NULL;     // Global head pointer, initially set to NULL

node * createLinkedList(){
    node*p;         //iterator
    node*newnode;   // Pointer to create a new node
    int choice=1;
    

    while(choice!=0){
        // Allocate memory for a new node and set its data
        newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL ;         ///make it null bhery fast otherwise tumhara brain null ho jayega
        printf("Enter data:");
        scanf("%d",&newnode->data);
    
        if(head==NULL){     //// If the list is empty, set the head to the new node
            head=newnode; 
        }

        else{
            p=head;     //here head is assigned to p for iteration i.e Firstly p points 15 then 78
            while(p->next!=NULL){
                p=p->next;    //its like p++  or // Move to the next node
            }
            p->next=newnode;  // Link the new node at the end
        }

        printf("Do you want to continue (1|0) is (Y|N):");
        scanf("%d",&choice);
    }
      //EXAMPLE --->  15->78->55->NULL    87->NULL(created node)
}

//here void is used as it return nothing so otherwise if it return something then int will be used
    
    void display(){
    node *p= head; //The statement Node* p = head; copies the value of the head pointer into the p (iterator)
                   //This assigns the value of head to p
    
    if (p== NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    while(p!=NULL){     // why not p->next != NULL , this is because when p is in the last element, the next of P is NULL so the loop breaks, but we need to print this element right so that is why, we can use do-while to acheive the same though ;)
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");  // End of the list
}


int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a node\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createLinkedList();
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;  // Exit the program
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}


