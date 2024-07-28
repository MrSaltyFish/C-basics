#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 999999
// Binary Tree Node
struct BSTnode {
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};
typedef struct BSTnode* BSTNODE;

BSTNODE createBSTNODE(int data) {
    BSTNODE temp = (BSTNODE)malloc(sizeof(struct BSTnode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BSTNODE insertBSTNODE(BSTNODE root, int ele) {
    if(root == NULL) {
        printf("Creating a node");
        root = createBSTNODE(ele);
    } else if(ele > root->data) {
        root->right = insertBSTNODE(root->right, ele);
    } else if(ele < root->data) {
        root->left = insertBSTNODE(root->left, ele);
    } else {
        printf("\nElement is already present in BSTNODE");
        return root;
    }
    return root;
}

BSTNODE inOrderPredecessor(BSTNODE root) {
    root = root->left;
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

BSTNODE deleteBSTNODE(BSTNODE root, int ele) {
    BSTNODE prev;

    if(root == NULL) {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    if(ele < root->data) {
        root->left = deleteBSTNODE(root->left, ele);
    } else if(ele > root->data) {
        root->right = deleteBSTNODE(root->right, ele);
    } else {
        // reached node
        prev = inOrderPredecessor(root);  // IN-Order Predecessor
        root->data = prev->data;
        root->left = deleteBSTNODE(root->left, prev->data);
    }
    return root;
}

void inorderInBST(BSTNODE root) {
    if(root != NULL) {
        inorderInBST(root->left);
        printf("%d ", root->data);
        inorderInBST(root->right);
    }
}
void preorderInBST(BSTNODE root) {
    if(root != NULL) {
        preorderInBST(root->left);
        printf("%d ", root->data);
        preorderInBST(root->right);
    }
}
void postorderInBST(BSTNODE root) {
    if(root != NULL) {
        postorderInBST(root->left);
        printf("%d ", root->data);
        postorderInBST(root->right);
    }
}

int main() {
    BSTNODE root = createBSTNODE(MAX);
    int input;
    printf("Creating a BST:- ");
    while(input != -1) {
        printf("\nEnter data (-1 to end): ");
        scanf("%d", &input);
        insertBSTNODE(root, input);
    }

    printf("\n");
    inorderInBST(root);

    printf("\nEnter data to delete: ");
    scanf("%d", &input);
    deleteBSTNODE(root, input);

    printf("\n");
    inorderInBST(root);

    printf("\nprogram ended ");
    scanf("%d", &input);
    return 0;
}