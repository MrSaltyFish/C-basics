#include <stdio.h>
#include <stdlib.h>

//------Basic Structure------
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

//------- Creating a node in memory and returning its pointer -------
NODE createNode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = 0;
    temp->next = NULL;
    return temp;
}

//------- Circular Linked List Menu ------
void printMenu()
{
    printf("1. Add a node at the beginning of DLL");
    printf("\n2. Add a node at the end of DLL");
    printf("\n3. Add a node at the specified position in DLL");
    printf("\n4. Delete a node in the beginning of DLL");
    printf("\n5. Delete a node in the end of DLL");
    printf("\n6. Delete a node at the specified position in DLL");
    printf("\n7. Print the Linked List in forward order");
    printf("\n8. Print the Linked List in reverse order");
    printf("\n0. Exit the program");
    printf("\n\nEnter your choice : ");
}
