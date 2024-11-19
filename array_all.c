#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void insert(int value, int pos) {
    if (size == MAX_SIZE || pos < 1 || pos > size + 1) {
        printf("Invalid operation.\n");
        return;
    }
    for (int i = size; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    size++;
}

void delete (int pos) {
    if (size == 0 || pos < 1 || pos > size) {
        printf("Invalid operation.\n");
        return;
    }
    for (int i = pos - 1; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
}

void display() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n==== Array Operations Menu ====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert(value, 1);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert(value, size + 1);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insert(value, pos);
                break;

            case 4:
                printf("Deleting from beginning...\n");
                delete(1);
                break;

            case 5:
                printf("Deleting from end...\n");
                delete(size);
                break;

            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &pos);
                delete(pos);
                break;

            case 7:
                printf("Current Array: ");
                display();
                break;

            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
