#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(struct Node* root){
    if(root != NULL){
        printf("%d", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->value);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->value);
    }
}

int main(){
    /*
        Tree created:
              1
             / \
            2   3
           / \
          4   5
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}