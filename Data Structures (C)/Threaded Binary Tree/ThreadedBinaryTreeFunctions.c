#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_VALUE 65536

struct ThreadedBinaryNode {
    int data;
    struct ThreadedBinaryNode *left;
    struct ThreadedBinaryNode *right;
    int leftThread;
    int rightThread;
    // integers represent that the node exists
};
typedef struct ThreadedBinaryNode *TBNODE;
TBNODE root = NULL;

void insert(int data) {
    TBNODE traverseNode = root;

    while(true) {
        if(traverseNode->data < data) {
            if(traverseNode->rightThread) {
                break;
            }
            traverseNode = traverseNode->right;
        } else if(traverseNode->data > data) {
            if(traverseNode->leftThread) {
                break;
            }
            traverseNode = traverseNode->left;
        } else {
            printf("Duplicates are not allowed. \n");
            return;
        }
    }

    TBNODE temp = (TBNODE)malloc(sizeof(struct ThreadedBinaryNode));
    temp->data = data;
    temp->leftThread = true;
    temp->rightThread = true;

    if(traverseNode->data < data) {
        temp->right = traverseNode->right;
        temp->left = traverseNode;
        traverseNode->right = temp;
        traverseNode->rightThread = false;
    } else {
        temp->right = traverseNode;
        temp->left = traverseNode->left;
        traverseNode->left = temp;
        traverseNode->leftThread = false;
    }
}

void traverseTree() {
    TBNODE printNode = root;
    TBNODE p;

    while(true) {
        p = printNode;
        printNode = printNode->right;

        if(!p->rightThread) {
            while(!printNode->leftThread) {
                printNode = printNode->left;
            }
        }

        if(printNode == root) {
            break;
        }

        printf("%d ", printNode->data);
    }
    printf("\n");
}

void delete(int ele) {
    TBNODE dest = root->left;
    TBNODE p = root;

    while(true) {
        if(dest->data < ele) {
            if(dest->rightThread) {
                printf("Cannot find %d in the threaded binary tree.\n", ele);
                return;
            }
            p = dest;
            dest = dest->right;
        } else if(dest->data > ele) {
            if(dest->leftThread) {
                printf("Cannot find %d in the threaded binary tree.\n", ele);
                return;
            }
            p = dest;
            dest = dest->left;
        } else {
            break;
        }
    }

    TBNODE target = dest;

    // Destination has two children
    // Finding largest node of left child
    if(!dest->rightThread && !dest->leftThread) {
        p = dest;
        target = dest->left;
        while(!target->rightThread) {
            p = target;
            target = target->right;
        }
        dest->data = target->data;
    }

    // Deletion in the right subtree
    if(p->data > target->data) {
        if(target->leftThread && target->rightThread) {
            // The node to be deleted has both children
            p->left = target->left;
            p->leftThread = true;
        } else if(target->rightThread) {
            // The node to be deleted has only right child
            // Finding largest node
            TBNODE largest = target->left;

            while(!largest->rightThread) {
                largest = largest->right;
            }
            p = largest->right;
            p->left = target->left;
        } else {
            // The node to be deleted has only left child
            // Finding smallest node
            TBNODE smallest = target->right;

            while(!smallest->leftThread) {
                smallest = smallest->right;
            }
            smallest->left = target->left;
            p->left = target->right;
        }
    } else {
        // Deletion in left subtree
        if(target->leftThread && target->rightThread) {
            // The node to be deleted has both children
            p->right = target->right;
            p->rightThread = true;
        } else if(target->rightThread) {
            // The node to be deleted has only right child
            // Finding largest node
            TBNODE largest = target->left;

            while(!largest->rightThread) {
                largest = largest->right;
            }
            largest->right = target->right;
            p->right = target->left;
        } else {
            // The node to be deleted has only left child
            // Finding smallest node
            TBNODE smallest = target->right;

            while(!smallest->leftThread) {
                smallest = smallest->left;
            }
            smallest->left = p;
            p->right = target->right;
        }
    }
}

int search(int ele) {
    TBNODE tmp = root->left;

    while(true) {
        if(tmp->data < ele) {
            if(tmp->rightThread) {
                return false;
            }
            tmp = tmp->right;
        } else if(tmp->data > ele) {
            if(tmp->leftThread) {
                return false;
            }
            tmp = tmp->left;
        } else {
            return true;
        }
    }
}

void printMenu() {
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Search an element\n");
    printf("4. Traversal\n");
    printf("0. Exit\n");
}

int main() {
    int data, userOption, pos;
    root = (TBNODE)malloc(sizeof(struct ThreadedBinaryNode));
    root->data = MAX_VALUE;
    root->right = root->left = root;
    root->leftThread = true;

    while(true) {
        printMenu();
        printf("Enter your option: ");
        scanf("%d", &userOption);
        switch(userOption) {
            case 1:
                printf("Enter an element to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                printf("Enter an element to be deleted: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                printf("Enter an element to be searched: ");
                scanf("%d", &data);
                pos = search(data);

                if(pos) {
                    printf("Element found in threaded binary tree.\n");
                } else {
                    printf("Element not found in threaded binary tree.\n");
                }
                pos = 0;
                break;
            case 4:
                if(root->right == root && root->left == root) {
                    printf("Threaded binary tree is empty.\n");
                } else {
                    printf("Elements of the threaded binary tree: ");
                    traverseTree();
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}