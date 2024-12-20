//C prog that have the three Binary tree traversal in it:(Manual)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
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
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);

    //Display all:
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

/*
               1
             /   \
           2       3
         /   \    /   \
        4     5  6     7
*/