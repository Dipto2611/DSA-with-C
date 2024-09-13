#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

int normalEntry()
{
    int choice = 1;
    node *newnode;
    node *p;

    while (choice != 0)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        printf("Enter data:");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            // 89->88->NULL  45->NULL
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newnode;
        }

        printf("Do you want to continue (1|0) is (Y|N):");
        scanf("%d", &choice);
    }
}

void insert_at_begin(int val)
{
    node *p;

    node *newnode = normalEntry(val);
    p->next = head;
    head = p;
}

void insert_at_end(int val)
{
    node *newnode = normalEntry(val);

    if (head = NULL)
    {
        head = newnode;
        return;
    }
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode; // attached it to the newnode (remember)
    }
}

int tailvalue = 0;

int length()
{
    node *p = head; // head must be assigned!
    int count = 0;

    while (p != NULL)
    { // to print the whole series len()
        p = p->next;
        count++;
    }

    tailvalue = count;
    return count;
}

// Why not initialize p or temp to head?

// Initializing p or temp to head depends on the operation you are going to perform. For example, if you are inserting a node at the tail, you'll likely traverse the list from the head, so you might assign p = head when the traversal starts.
// However, it's not always necessary to initialize p or temp with head right away, especially if you're not yet sure whether you're performing an operation at the head, tail, or middle of the list.
// Initializing them to NULL at the beginning gives flexibility. When the exact position is determined (like the location you input via scanf), you can set them accordingly.

void insert_specific()
{
    node *p = NULL;
    node *temp = NULL;
    int loc;
    printf("Enter the location:");
    scanf("%d", &loc);

    // if(loc>length()){
    //     printf("Exceeds the limit");
    // }
    // else{
    //     if (tailvalue==0){ ///simply the len only
    //         printf("\nEmpty list, Create the list first");
    //     }
    //     printf("New Data: ");
    //     int val;
    //     temp=normalEntry(val);

    if (loc > length() || tailvalue == 0 || loc < 0)
    {
        printf("Invalid entry.");
    }
    else
    {
        printf("New Data: ");
        int val;
        temp=normalEntry(val);
        
        //insert at start:
        if (loc == 0)
        {
            return insert_at_begin(val);
        }

        else if (loc == tailvalue)  
        {
            return insert_at_end(val);
        }
        else
        {
            p = head;
            for (int index = 0; index < loc - 1; index++)
            {
                p = p->next;
            }
            // linking part;
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void display()
{

    if (length() == 0)
    {
        printf("\nEmpty linked list");
    }
    else
    {
        node *p = NULL;

        p = head;
        while (p != NULL)
        {

            printf("%d->", p->data);
            p = p->next;
        }
    }
}

int main()
{
    int choice, data, location;

    while (1)
    {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Location\n");
        printf("4. Print List\n");
        printf("5. Print Length\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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

            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
