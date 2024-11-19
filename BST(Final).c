/*      Final code for BST with search func in it:      */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;


node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


node* insertion(node* root, int data) { //remember root and data must be here for arguments
    
    if (root == NULL) {
        return createnode(data);
    }
    // Recursively insert the node based on value
    if (data < root->data) {
        root->left = insertion(root->left, data);
    } else if (data > root->data) {
        root->right = insertion(root->right, data);
    }
    return root;
}

//Search func:

node* search(node* root, int key) { //with root one extra key data is inserted//
    if (root == NULL || root->data == key) {
        return root; // Return the node if found or NULL if not found
    }
    if (key < root->data) {
        return search(root->left, key); // Search in the left subtree
    }
    return search(root->right, key); // Search in the right subtree
}

// Inorder traversal: left -> root -> right
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    node* root = NULL; // Initialize the root pointer to NULL /*F. IMP root ko null kro first*/
    int key; //new thing

    // Insert nodes into the binary tree
    root = insertion(root, 50);
    insertion(root, 10);
    insertion(root, 45);
    insertion(root, 12);
    insertion(root, 78);
    insertion(root, 96);

    /* first print the list then only its easy to search yk*/
    printf("Inorder traversal of the binary tree:\n");
    inorderTraversal(root);
    printf("\n");

    
    printf("Enter a value to search in the tree: ");
    scanf("%d", &key);
    if (search(root, key) != NULL) { //remainder search(root, key) format imp
        printf("Value %d found in the tree.\n", key);
    } else {
        printf("Value %d not found in the tree.\n", key);
    }

    return 0;
}
