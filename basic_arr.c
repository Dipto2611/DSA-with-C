#include <stdio.h>
#define N 5

//using while
int main(){
    int arr[N];
    int val=0;
    printf("Entered values are:\n");
    while (val<N)
    {
        scanf("%d",&arr[val]);
        val++;

    }
    val=0;
    printf("Entered values are: ");
    while (val<N)
    {
        printf("%d ",arr[val]);
        val++;
    }
}

//.....................................................................................

//using for 
#include <stdio.h>
#define N 5

int main(){
    int arr[N];

    
    for(int i=0;i<N;i++){
        printf("Enter the vals:\n");
        scanf("%d",&arr[i]);
    }
    printf("\n");

    printf("Entered elements are: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
        
    }

}
