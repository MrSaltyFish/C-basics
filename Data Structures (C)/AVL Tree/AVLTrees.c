#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 999999
// AVL Tree Node
struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};
typedef struct AVLNode* AVLNODE;

int max(int a, int b) { return a > b ? a : b; }

int getHeight(AVLNODE root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(AVLNODE node) {
    if(node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNODE createAVLNODE(int ele) {
    AVLNODE root = (AVLNODE)malloc(sizeof(struct AVLNode));
    root->data = ele;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;

    return root;
}

AVLNODE leftRotate(AVLNODE x) {
    AVLNODE y = x->right;
    AVLNODE T2 = y->left;
    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

AVLNODE rightRotate(AVLNODE y) {
    AVLNODE x = y->left;
    AVLNODE T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

AVLNODE insertAVLNODE(AVLNODE node, int key) {
    if(node == NULL) {
        return (createAVLNODE(key));
    }

    if(key < node->data) {
        node->left = insertAVLNODE(node->left, key);
    } else if(key > node->data) {
        node->right = insertAVLNODE(node->right, key);
    } else {
        printf("\nElement already exists.");
        return NULL;
    }
    return node;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    int bf = getBalanceFactor(node);

    // LL rotation
    if(bf > 1 && key < node->left->data) {
        return rightRotate(node);
    }
    // RR rotation
    if(bf < -1 && key < node->right->data) {
        return leftRotate(node);
    }
    // LR rotation
    if(bf > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL rotation
    if(bf < -1 && key > node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorderInAVL(AVLNODE root) {
    if(root != NULL) {
        inorderInAVL(root->left);
        printf("%d ", root->data);
        inorderInAVL(root->right);
    }
}
void preorderInAVL(AVLNODE root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorderInAVL(root->left);
        preorderInAVL(root->right);
    }
}
int main() {
    /*
    AVLNODE root = createAVLNODE(MAX);
    int input;
    printf("Creating a AVL Tree:- ");
    while(input != -1) {
        printf("\nEnter data (-1 to end): ");
        scanf("%d", &input);
        insertAVLNODE(root, input);
    }
    */
    AVLNODE root = NULL;
    int input;
    root = insertAVLNODE(root, 1);
    root = insertAVLNODE(root, 2);
    root = insertAVLNODE(root, 4);
    root = insertAVLNODE(root, 5);
    root = insertAVLNODE(root, 6);
    root = insertAVLNODE(root, 3);
    printf("\n");
    inorderInAVL(root);
    printf("\n");
    preorderInAVL(root);

    printf("\nprogram ended ");
    scanf("%d", &input);
    return 0;
}