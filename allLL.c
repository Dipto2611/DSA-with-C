#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;

node* normalEntry() {
    int choice = 1;
    node* newnode;
    node* p; //pointer
    while (choice != 0) {
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (head == NULL) {
            head = newnode;
        } else {
            p = head;  // Initialize p to head
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newnode;
        }
        printf("Do you want to continue (1|0) is (Y|N): ");
        scanf("%d", &choice);
    }
}

void insert_at_begin(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insert_at_end(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newnode;
}

int length() {
    node* p = head;
    int count = 0;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

void insert_specific(int val, int loc) {
    if (loc > length()) {
        printf("Exceeds the limit\n");
    } else {
        if (loc == 0) {
            insert_at_begin(val);
        } else if (loc == length()) {
            insert_at_end(val);
        } else {
            node* newnode = (node*)malloc(sizeof(node));
            newnode->data = val;
            newnode->next = NULL;
            node* p = head;
            for (int index = 0; index < loc - 1; index++) {
                p = p->next;
            }
            newnode->next = p->next;
            p->next = newnode;
        }
    }
}

void delete_at_begin() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    node* temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node* p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

void delete_specific(int loc) {
    if (loc >= length()) {
        printf("Exceeds the limit\n");
        return;
    }
    if (loc == 0) {
        delete_at_begin();
    } else {
        node* p = head;
        for (int index = 0; index < loc - 1; index++) {
            p = p->next;
        }
        node* temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
}

void display() {
    if (length() == 0) {
        printf("\nEmpty linked list\n");
    } else {
        node* p = head;
        while (p != NULL) {
            printf("%d->", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, data, location;
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Location\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Location\n");
        printf("7. Print List\n");
        printf("8. Print Length\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_begin(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter location: ");
                scanf("%d", &location);
                insert_specific(data, location);
                break;
            case 4:
                delete_at_begin();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter location to delete: ");
                scanf("%d", &location);
                delete_specific(location);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Length of the list: %d\n", length());
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
