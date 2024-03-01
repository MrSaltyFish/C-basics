#include <stdio.h>
#include <stdlib.h>

//------Basic Structure------
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

//------- Creating a node in memory and returning its pointer -------
NODE createNode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = 0;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

//------ Adding a node in a DCLL at the beginning ------

// HAS PROBLEMS
NODE insertAtBeginDCLL(NODE head, int data)
{
    NODE addNode = createNode();
    addNode->data = data;

    if (head == NULL)
    {
        head = addNode;
        addNode->next = addNode;
        addNode->prev = addNode;
        return head;
    }

    NODE lastNode = head->prev;
    lastNode->next = addNode;
    addNode->prev = lastNode;

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
        addNode->prev = addNode;
    }
    else
    {
        NODE lastNode = head->prev;
        lastNode->next = addNode;
        addNode->prev = lastNode;
    }
    addNode->next = head;
    head->prev = addNode;

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

//------ Print the DCLL Forwards ------
void printForwardsDCLL(NODE head)
{
    NODE printNode = head;

    do
    {
        printf("%d --> ", printNode->data);
        printNode = printNode->next;
    } while (printNode != head);
    printf("HEAD\n\n");
}

//------ Print the DCLL Backwards ------
void printBackwardsDCLL(NODE head)
{
    NODE printNode = head;
    do
    {
        printf("%d <-- ", printNode->data);
        printNode = printNode->prev;
    } while (printNode != head);
    printf("HEAD\n\n");

    // NODE tail = head;
    // while (tail->next != head)
    // {
    //     tail = tail->next;
    // }

    // while (tail->prev != head)
    // {
    //     printf(" <-- %d", tail->data);
    //     tail = tail->prev;
    // }
    // printf(" <-- %d", tail->data);
    // printf("\n\n");
}

//------- Double Circular Linked List Menu ------
void printMenuDCLL()
{
    printf("1. Add a node at the beginning of DCLL");
    printf("\n2. Add a node at the end of DCLL");
    printf("\n3. Add a node at the specified position in DCLL");
    printf("\n4. Delete a node in the beginning of DCLL");
    printf("\n5. Delete a node in the end of DCLL");
    printf("\n6. Delete a node at the specified position in DCLL");
    printf("\n7. Print the DCLL in forward order");
    printf("\n8. Print the DCLL in reverse order");
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
                printForwardsDCLL(head);
            }
            break;
        case 8:
            if (head == NULL)
            {
                printf("DCLL is empty.\n\n");
            }
            else
            {
                printBackwardsDCLL(head);
            }
            break;

        default:
            printf("Incorrect input, please try again.\n\n");
            break;
        }
    }
    return 0;
}