/// Whole linked list functions and ops///

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* head = NULL;   //make it null firstly

void normalEntry() {
    int choice = 1;
    node* newnode;
    node* p;  //pointer
    while (choice != 0) {
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (head == NULL) {
            head = newnode;
        } else {
            p = head;  // Initialize p to head
            while (p->next != NULL) {  //recall that eg 
                p = p->next;
            }
            p->next = newnode;
        }
        //Outside of that loop (Remember*) & inside of while
        printf("Do you want to continue (1|0) is (Y|N): ");
        scanf("%d", &choice);
    }
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

//  *INSERTION* :

//performing Right to Left insert
void insert_at_begin(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}
//performing Left to Right insert
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
    p->next = newnode;  //as before just link it
}


void insert_specific(int val, int loc) {
    
    if (loc < 0 || loc > length()) {
        printf("Invalid location\n");
    } 
    else {
        if (loc == 0) {
            insert_at_begin(val);
        
        } else if (loc == length()) {
            insert_at_end(val);
        
        } else {
            node* newnode = (node*)malloc(sizeof(node)); //here new node created
            newnode->data = val;
            newnode->next = NULL;
            
            node* p = head;  //pointing p to head
            for (int index = 0; index < loc - 1; index++) {  //here indexing k saaath chalega
                p = p->next;
            }
            newnode->next = p->next;
            p->next = newnode;
        }
    }
}

// *DELETION* :

void delete_at_begin() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    node* temp = head; //temp is assigned to head for traversal
    head = head->next; // just inc. the head to the next consecutive node and del the first one
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
    while (p->next->next != NULL) {   //as usual check till 2nd last node
        p = p->next;       //if not found, increment it as ususal
    }
    free(p->next);  //when finds it free the last node and make 2nd last_node->next to NULL
    p->next = NULL;
}

void delete_specific(int loc) {
    
    if (loc < 0 || loc > length()){
        printf("Invalid location\n");
        return;
    }
    
    if (loc == 0) {
        delete_at_begin();
    
    } else {
        node* p = head;
        for (int index = 0; index < loc - 1; index++) { //here indexing k saaath chalega
            p = p->next;
        }
        node* temp = p->next; // Node to delete
        p->next = p->next->next; //skips the del node and link the others by this
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
        printf("NULL\n"); //for printing last part to show null
    }
}

int main() {
    int choice, data, location;
    while (1) {
        printf("\nLinked List Operations:\n");
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
                normalEntry();  // Call the normal entry function for inserting multiple nodes
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
