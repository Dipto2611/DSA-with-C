#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;  // New pointer to track the previous node
} node;

node* head = NULL;  // Initial list head

void normalEntry() {
    int choice = 1;
    node* newnode;
    node* p;
    while (choice != 0) {
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->prev = NULL;  // Initialize prev to NULL
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (head == NULL) {
            head = newnode;
        } else {
            p = head;
            while (p->next != NULL) {  //traverse till null encountered
                p = p->next;
            }
            p->next = newnode;  //add the last node
            newnode->prev = p;  // Set the prev pointer of newnode to p
        }
        printf("Do you want to continue (1|0): ");
        scanf("%d", &choice);
    }
}

int length() {
    node* p = head;
    int count = 0;
    while (p != NULL) {
        p = p->next;
        count++; //inc.
    }
    return count; //will count the no of times it hits
}

void insert_at_begin(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head; // Set next of new node to the current head
    newnode->prev = NULL; // New node's prev is NULL because it's now the first node
    if (head != NULL) {  //head's null means the add. is there or not 
        head->prev = newnode;  //here creation of newnode is done
    }
    head = newnode;
}

void insert_at_end(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;   // Since it will be the last node, next is NULL
    newnode->prev = NULL;
    
    if (head == NULL) {
        head = newnode;
        return;
    }
    
    //here p is traversed till 2nd last node
    node* p = head;
    while (p->next != NULL) {   // Traverse to the last node
        p = p->next; //increment
    }
    p->next = newnode;
    newnode->prev = p;   // Set the new node's prev pointer to the 2nd last node
}

void insert_specific(int val, int loc) {
    if (loc < 0 || loc > length()) {
        printf("Invalid location\n");
        return;
    } else {
        if (loc == 0) {
            insert_at_begin(val);
        } else if (loc == length()) {
            insert_at_end(val);
        } else {
            node* newnode = (node*)malloc(sizeof(node));
            newnode->data = val;
            
            //go till 2nd last loc of that node
            node* p = head;
            for (int index = 0; index < loc - 1; index++) {
                p = p->next;
            }
            newnode->next = p->next; //(We didn't use the extra temp variable so we used p->nxt) (also, temp 2=p->nxt)
            newnode->prev = p; //prev node
            
            if (p->next != NULL) {
                p->next->prev = newnode;  //link part (left dirn)
            }
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
    head = head->next; // Move the head to the second node
    if (head != NULL) {
        head->prev = NULL; // Set the new head's prev pointer to NULL
    }
    free(temp); // Free the memory of the old head
}

//for deletion traversal is must.
void delete_at_end() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    if (head->next == NULL) {  // If there's only one node
        free(head);
        head = NULL;
        return;
    }
    
    node* p = head;
    while (p->next != NULL) {   // Traverse to the LAST node
        p = p->next;
    }
    p->prev->next = NULL;  //2nd last node's next is become null now
    free(p);
}

void delete_specific(int loc) {
    if (loc < 0 || loc > length()) {
        printf("Invalid location\n");
        return;
    }
    if (loc == 0) {
        delete_at_begin();
    } else {
        node* p = head;
        for (int index = 0; index < loc - 1; index++) {
            p = p->next;
        }
        
        //temp holds the data that is to be deleted
        node* temp = p->next;  // Store the node to be deleted
        p->next = temp->next; // Bypass the node to be deleted (deleted node k pehle wala node is linked to last node)
        if (temp->next != NULL) {
            temp->next->prev = p; //last node ka prev will contain the head's add i.e p 
        }
        free(temp);
    }
}

void display() {
    if (length() == 0) {
        printf("\nEmpty doubly linked list\n");
    } else {
        node* p = head;
        while (p != NULL) {
            printf("%d <-> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, data, location;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Normal Entry (Multiple Nodes)\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Location\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Location\n");
        printf("8. Print List\n");
        printf("9. Print Length\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                normalEntry();
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_begin(data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter location: ");
                scanf("%d", &location);
                insert_specific(data, location);
                break;
            case 5:
                delete_at_begin();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                printf("Enter location to delete: ");
                scanf("%d", &location);
                delete_specific(location);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Length of the list: %d\n", length());
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
