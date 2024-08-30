#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* head=NULL; 

int normalEntry(){
    int choice=1;
    node*newnode;

    while(choice!=0){
        newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        printf("Enter data:");
        scanf("%d",&newnode->data);

    
        if (head==NULL){
            printf("List is empty");
        }
        else{
            
        }
    }
}