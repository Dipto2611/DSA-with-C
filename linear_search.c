#include <stdio.h>
#define N 5

void LinearS(int arr[], int x) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            printf("Element %d found at index %d\n", x, i);
            return;   // Exit the function after finding the element.
        }
    }
    printf("Element %d not found in the array\n", x); //Msg outside the for loop
}

int main() {
    int arr[N];

    // Input 
    printf("Enter %d values:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Display
    printf("Entered elements are: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the value to search
    int x;
    printf("Enter a value to search: ");
    scanf("%d", &x);

    // Perform linear search
    LinearS(arr, x);

    return 0;
}
