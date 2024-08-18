#include <stdio.h>
#define N 5

int arr[N];
int f=-1;
int r=-1;

int isEmpty(){
    return (f==-1 && r==-1);
}

int isFull(){
    return ((r+1)%N==f); //change is here 
}

void enQ(int value){  ///argument pass is imp
    if(isFull()){
        printf("Circular Queue is Full.");
        return;
    }
    else if (isEmpty()){
        r=f=0;
    }
    else{
        r=(r+1)%N; //change is here
    }

    arr[r]=value; ///value is assigned to r of index
    printf("Enqueued element is %d",value);
}

void deQ(){
    if(isEmpty()){
        printf("Circular Queue is empty.");
        return;
    }

    else if(f==r){
        printf("Deleted element is %d",arr[f]);
        f=r=-1;          ///prev position
    }
    else{
        printf("Deleted element is: %d",arr[f]);
        f=(f+1)%N;  //new
    }

}

void display(){
    if(isEmpty()){
        printf("Circular Queue is empty.");
    }
    else{
        int i;
        for (i=f; i!=r; i=(i + 1)%N){
        printf("%d\t",arr[i]); //arr[i] here means value at that address 
        }
        printf("%d",arr[r]); // explicitly print the last element

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
    
        switch(choice)
        {
               case 1:
                printf("Enter value:");
                scanf("%d",&value);
                enQ(value);
                break;
            case 2: deQ();
                break;
            case 3: display();
                break;
            case 4:
                return 0;
            default:printf("Invalid input.");
                break;
        }

    }
    return 0;
}



