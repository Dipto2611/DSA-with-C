#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* head=NULL; 

int normalEntry(){
    int choice=1;
    node*newnode;
    node*p;

    while(choice!=0){
        newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        printf("Enter data:");
        scanf("%d",&newnode->data);
        
        if (head==NULL){
            head=newnode;
        }
        else{
                //89->88->NULL  45->NULL
            while(p->next!=NULL){
                p=p->next;
            }                
            p->next=newnode;
        }
        
        printf("Do you want to continue (1|0) is (Y|N):");
        scanf("%d",&choice);
    }

}

void insert_at_begin(){
    node*p;

    node*newnode=normalEntry();
    p->next=head;
    head=p;

}