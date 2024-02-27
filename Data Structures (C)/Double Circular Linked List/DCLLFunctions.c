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

//------ Adding a node in a DCLL at the beginning ------
NODE insertAtBeginDCLL(NODE head, int data)
{
    NODE addNode = createNode();
    addNode->data = data;

    if (head == NULL)
    {
        head = addNode;
        addNode->next = addNode;
        return head;
    }

    NODE lastNode = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    addNode->next = head;
    lastNode->next = addNode;
    head = addNode;

    return head;
}

//------ Adding a node in a DCLL at the end -------
NODE insertAtEndDCLL(NODE head, int data)
{
    NODE addNode = createNode();
    addNode->data = data;

    if (head == NULL)
    {
        head = addNode;
        addNode->next = addNode;
        return head;
    }

    NODE lastNode = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    addNode->next = head;
    lastNode->next = addNode;

    return head;
}

//------ Adding a node in a DCLL at the specified position -------
NODE insertAtPositionDCLL(NODE head, int data, int position)
{
    return head;
}

//------ Deleting a node in a DCLL at the beginning ------
NODE deleteAtBeginDCLL(NODE head)
{

    return head;
}
//------ Deleting a node in a DCLL at the end -------
NODE deleteAtEndDCLL(NODE head)
{

    return head;
}
//------ Deleting a node in a DCLL at the specified position -------
NODE deleteAtPositionDCLL(NODE head, int position)
{

    return head;
}

//------ Print the DCLL ------
void printDCLL(NODE head)
{
    NODE printNode = head;

    do
    {
        printf("%d --> ", printNode->data);
        printNode = printNode->next;
    } while (printNode != head);

    printf("(FIRST)\n\n");
}

//------- Circular Linked List Menu ------
void printMenuDCLL()
{
    printf("1. Add a node at the beginning of DCLL");
    printf("\n2. Add a node at the end of DCLL");
    printf("\n3. Add a node at the specified position in DCLL");
    printf("\n4. Delete a node in the beginning of DCLL");
    printf("\n5. Delete a node in the end of DCLL");
    printf("\n6. Delete a node at the specified position in DCLL");
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
    int position = 0;
    while (userChoice)
    {
        printMenuDCLL();
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 0:
            return 0;

        case 1:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtBeginDCLL(head, data);
            printf("\n");
            break;
        case 2:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtEndDCLL(head, data);
            printf("\n");
            break;
        case 3:

            printf("Enter input data : ");
            scanf("%d", &data);
            printf("Enter position to insert data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = insertAtBeginDCLL(head, data);
            }
            else
            {
                head = insertAtPositionDCLL(head, data, position);
            }
            printf("\n");
            break;
        case 4:
            head = deleteAtBeginDCLL(head);
            break;
        case 5:
            head = deleteAtEndDCLL(head);
            break;
        case 6:
            printf("Enter position to delete data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = deleteAtBeginDCLL(head);
            }
            else
            {
                head = deleteAtPositionDCLL(head, position);
            }
            break;
        case 7:
            if (head == NULL)
            {
                printf("DCLL is empty.\n\n");
            }
            else
            {
                printDCLL(head);
            }
            break;
        case 8:
            if (head == NULL)
            {
                printf("DCLL is empty.\n\n");
            }
            else
            {
                printCLL(head);
            }
        default:
            printf("Incorrect input, please try again.\n\n");
            break;
        }
    }
    return 0;
}