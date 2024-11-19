//Prog to implement a basic Binary Tree:

//Remember BinTree only follows Inorder path:
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createnode(int data) {   //use only node* dont go for int or void
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//inorder - left ->root->right
void inorderTraversal(Node* root) { //here use void for func
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = createnode(7);
    root->left = createnode(21);
    root->right = createnode(34);
    root->left->left = createnode(4);
    root->left->right = createnode(42);
    root->right->left = createnode(88);
    root->right->right = createnode(2);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

/*
               7
             /   \
           21     34
         /   \    /  \
        4    42  88   2
*/