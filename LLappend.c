# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}node;

struct node* head;
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
node* normalEntry(){
    node* temp=NULL;
    
    int data;
    char userChoice='y';
    node* i;
    while (userChoice != 'n'){
        
        temp = (node*)malloc(sizeof(node));
        
        printf("Data: ");
        scanf("%d",&temp->data);
        if (head == NULL){
            head = temp;
            temp->next = NULL;
                //coz there was nothing before temporary node
        }else{
            
            // temp->next = NULL;
            i = head;
            while (i->next != NULL)
            {
                i = i->next;
            }
            
            i->next = temp;
            temp->next = NULL;
            
        }

        printf("\nContinue?(y/n) ");
        scanf(" %c",&userChoice);

    }

    
}
void append(){
    node* newnode = NULL;
    int location=0;
    int userchoice = 0;

    
    
        printf("LOCATION:");
        scanf("%d",&location);
        if (location<0){
            printf("\nInvalid");
            return;
        }
        else{

            newnode = (node*)malloc(sizeof(node));
            newnode->next = NULL;

            printf("Data: ");
            scanf("%d",&newnode->data);

            if (location == 0){
                // [data|next]

                newnode->next = head;
                head = newnode;
            }
        }
        
    
}
int main(){
    int choice ;
while(1){
    printf("\nChoose: ");
    scanf("%d",&choice);

    if (choice == 1){
        normalEntry();
    }else if (choice == 2){
        append();
    }else if (choice == 3){
        display();
    }

}
}

