/*Algorithm:
    1. struct a node to get started
    2. create a node
    3. insertion of node to it and forming of bst
    4. write the func for preorder
    5. take the input
    6. show the output
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

// Function to insert a node in the binary tree
node* insertion(node* root, int data) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        return createnode(data); 
    }
    // Recursively insert the node based on value
    if (data < root->data) {                   //here root is holding the data value now
        root->left = insertion(root->left, data);
    } else if (data > root->data) {
        root->right = insertion(root->right, data);
    }
    return root;
}

// Preorder traversal: root -> left -> right

void preorderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal: left -> root -> right

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Postorder traversal: left -> right -> root

void postorderTraversal(node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node* root = NULL;  // Initialize the root pointer to NULL

    // Insert nodes into the binary tree
   
    root=insertion(root,50); //declaration of root
    insertion(root,10);
    insertion(root,45);
    insertion(root,12);
    insertion(root,78);
    insertion(root,96);

    // Display the tree in different traversal orders
    printf("Preorder traversal of the binary tree:\n");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal of the binary tree:\n");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary tree:\n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
