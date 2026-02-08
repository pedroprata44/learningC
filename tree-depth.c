#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

int depth(struct Node* root, struct Node* target, int level) {
    if (root == NULL)
        return -1;

    if (root == target)
        return level;

    int leftDepth = depth(root->left, target, level + 1);
    if (leftDepth != -1)
        return leftDepth;

    return depth(root->right, target, level + 1);
}

int main() {
    struct Node* root = malloc(sizeof(struct Node));
    struct Node* n5 = malloc(sizeof(struct Node));

    root->value = 10;
    n5->value = 5;

    root->left = n5;
    root->right = NULL;

    int level = depth(root, n5, 0);

    printf("Depth -> %d", level);

    return 0;
}