#include<stdio.h>
#define N 5

int arr[N];
int f=-1;
int r=-1;

int isEmpty(){          //as int used coz we are returning a value
    return (f==-1 && r==-1); //to check its out of box 
    
}

int isFull(){
    return (r==N-1); // to check within the size
}

void enQ(int value){                //here no val is coming so void used
    if(isFull()){
        printf("Queue is full.");
        return;
    }
    else if(isEmpty()){  
        r=f=0;             // initialization to 1st index
    }
    else{
        r++;               // else ek ghar aage badha do
    }
    arr[r]=value;
    printf("Enqueued: %d\n", value); //// Confirmation message
}

void deQ(){
    if(isEmpty()){
        printf("Queue is empty.");
        return ;
    }
    if (f==r){  ///when only 1 item is present in list
        printf("Deleted element is: %d\n", arr[f]); //new line
        f=r=-1; // pop this out and return the pointer to prev pos. i.e -1
    }
    else{
        printf("Deleted element is: %d",arr[f]);
        f++;  ///otherwise pop out krke one step ahead krlo!!
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty.\n");
        
    }
    else{
        int i;
        for(i=f;i<=r;i++){  //as f is 1st pos so i=f and "<=" bhery imp to use
            printf(" %d\t",arr[i]); 
        }
    }
}

int main(){
    int choice;
    int value;

    while(1){
        printf("\nOperation you want to perform:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    


        switch (choice)
        {
        case 1: printf("Enter the element:");
            scanf("%d",&value);
            enQ(value);
            break;
        case 2: deQ();
            break;
        case 3: display();
            break;
        case 4:
            return 0;

        default:printf("Invalid input entered");
        break;
        }
    }
    return 0;
}

