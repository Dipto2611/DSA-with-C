#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} node;

node* createnode(int data) {  ///here only the node* is used 
    node* newnode = (node*)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    
    return newnode;
}

void inorder(node* root) {  //here for func use the void 
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node* root = createnode(9);
    root->left = createnode(5);
    root->right = createnode(10);
    root->left->left = createnode(4);
    root->left->left->left = createnode(3);
    root->left->right = createnode(6);
    root->right->left = createnode(11);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
