#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Global head pointer
Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBegin(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


// Function to insert a node at a specific location
void insertAtLocation(int data, int location) {
    // Handle invalid location
    if (location < 0) {
        printf("Invalid location\n");
        return;
    }

    // Create a new node
    Node* newNode = createNode(data);

    // Insert at the beginning
    if (location == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Find the node just before the insertion point
    Node* temp = head;
    for (int i = 0; i < location - 1; i++) {
        if (temp == NULL) {
            printf("Location out of bounds\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}


// Function to calculate the length of the linked list
int length() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to print the linked list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate linked list operations
int main() {
    int choice, data, location;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Location\n");
        printf("4. Print List\n");
        printf("5. Print Length\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter location: ");
                scanf("%d", &location);
                insertAtLocation(data, location);
                break;
            case 4:
                printList();
                break;
            case 5:
                printf("Length of the list: %d\n", length());
                break;
            case 6:
                // Free allocated memory before exiting
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}