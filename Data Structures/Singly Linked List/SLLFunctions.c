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

//------ Adding a node in a SLL at the beginning ------
NODE insertAtBegin(NODE head, int data)
{
    NODE beginNode = createNode();
    beginNode->data = data;
    beginNode->next = head;
    head = beginNode;


    return head;
}

//------ Adding a node in a SLL at the end -------
NODE insertAtEnd(NODE head, int data)
{

    return head;
}
//------ Adding a node in a SLL at the specified position -------
NODE insertAtPosition(NODE head, int data)
{

    return head;
}
//------ Deleting a node in a SLL at the beginning ------
NODE deleteAtBegin(NODE head)
{

    return head;
}

//------ Deleting a node in a SLL at the end -------
NODE deleteAtEnd(NODE head)
{

    return head;
}

//------ Deleting a node in a SLL at the specified position -------
NODE deleteAtPosition(NODE head, int position)
{

    return head;
}

//------ Print the SLL ------
void printSLL(NODE head)
{
    NODE printNode = head;

    while (printNode != NULL)
    {
        printf("%d --> ", printNode->data);
        printNode = printNode->next;
    }
    printf("NULL\n");
}

//------- Singly Linked List Menu ------
void printMenu()
{
    printf("1. Add a node at the beginning of SLL");
    printf("\n2. Add a node at the end of SLL");
    printf("\n3. Add a node at the specified position in SLL");
    printf("\n4. Delete a node in the beginning of SLL");
    printf("\n5. Delete a node in the end of SLL");
    printf("\n6. Delete a node at the specified position in SLL");
    printf("\n7. Print the Linked List");
    printf("\n0. Exit the program");
    printf("\n\nEnter your choice : ");
}

//======= (MAIN Function) =======
int main()
{
    NODE head = NULL;
    int userChoice = 1;
    int data = 0;
    while (userChoice)
    {
        printMenu();
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 0:
            return 0;

        case 1:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtBegin(head, data);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            if (head == NULL)
            {
                printf("SLL is empty.\n\n");
            }
            else
            {
                printSLL(head);
            }
            break;
        default:
            printf("Incorrect input, please try again.\n\n");
            break;
        }
    }
    return 0;
}