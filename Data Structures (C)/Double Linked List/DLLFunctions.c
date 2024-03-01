#include <stdio.h>
#include <stdlib.h>

//------Basic Structure------
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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

//------ Adding a node in a DLL at the beginning ------
NODE insertAtBeginDLL(NODE head, int data)
{
    NODE addNode = createNode();
    addNode->data = data;

    if (head == NULL)
    {
        head = addNode;
        return head;
    }
    addNode->next = head;
    head->prev = addNode;
    head = addNode;
    return head;
}

//------ Adding a node in a DLL at the end -------
NODE insertAtEndDLL(NODE head, int data)
{
    NODE addNode = createNode();
    addNode->data = data;

    if (head == NULL)
    {
        head = addNode;
        return head;
    }

    NODE lastNode = head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = addNode;
    addNode->prev = lastNode;
    return head;
}

//------ Adding a node in a DLL at the specified position -------
NODE insertAtPositionDLL(NODE head, int data, int position)
{
    if (head == NULL)
    {
        printf("DLL is empty.\n\n");
        return head;
    }

    NODE addNode = createNode();
    addNode->data = data;
    NODE previous = head;
    NODE current = head;

    for (int i = 1; i < position; i++)
    {
        if (current == NULL)
        {
            printf("No such position in DLL.");
            return head;
        }

        previous = current;
        current = current->next;
    }

    previous->next = addNode;

    addNode->prev = previous;
    addNode->next = current;
    return head;
}

//------ Deleting a node in a DLL at the beginning ------
NODE deleteAtBeginDLL(NODE head)
{
    if (head == NULL)
    {
        printf("DLL is empty.\n\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    NODE deleteNode = head;
    head = head->next;
    head->prev = NULL;

    free(deleteNode);
    return head;
}
//------ Deleting a node in a DLL at the end -------
NODE deleteAtEndDLL(NODE head)
{
    if (head == NULL)
    {
        printf("DLL is empty.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    NODE previous = head;
    NODE current = head;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
    return head;
}

//------ Deleting a node in a DLL at the specified position -------
NODE deleteAtPositionDLL(NODE head, int position)
{
    if (position == 1)
    {
        free(head);
        return NULL;
    }

    NODE deleteNode = createNode();
    NODE previous = head;
    NODE current = head;

    for (int i = 1; i < position; i++)
    {
        if (current == NULL)
        {
            printf("No such position in DLL.\n\n");
            return head;
        }

        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("No such position in DLL.\n\n");
        return head;
    }
    if (current->next == NULL)
    {
        previous->next = NULL;
        free(current);
    }
    else
    {
        previous->next = current->next;
        (current->next)->prev = previous;
        free(current);
    }
    return head;
}

//------ Print the DLL Forwards ------
void printForwardsDLL(NODE head)
{
    NODE printNode = head;

    while (printNode != NULL)
    {
        printf("%d --> ", printNode->data);
        printNode = printNode->next;
    }
    printf("NULL\n\n");
}

//------ Print the DLL Backwards ------
void printBackwardsDLL(NODE head)
{
    printf("NULL");
    NODE tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    while (tail->prev != NULL)
    {
        printf(" <-- %d", tail->data);
        tail = tail->prev;
    }
    printf(" <-- %d", tail->data);
    printf("\n\n");
}

//------- Double Linked List Menu ------
void printMenuDLL()
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

//======= (MAIN Function) =======
int main()
{
    NODE head = NULL;
    int userChoice = 1;
    int data = 0;
    int position = 0;
    while (userChoice)
    {
        printMenuDLL();
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 0:
            return 0;
        case 1:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtBeginDLL(head, data);
            printf("\n");
            break;
        case 2:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtEndDLL(head, data);
            printf("\n");
            break;
        case 3:
            printf("Enter input data : ");
            scanf("%d", &data);
            printf("Enter position to insert data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = insertAtBeginDLL(head, data);
            }
            else
            {
                head = insertAtPositionDLL(head, data, position);
            }
            printf("\n");
            break;
        case 4:
            head = deleteAtBeginDLL(head);
            printf("\n");
            break;
        case 5:
            head = deleteAtEndDLL(head);
            printf("\n");
            break;
        case 6:
            if (head == NULL)
            {
                printf("DLL is empty.\n\n");
                break;
            }

            printf("Enter position to delete data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = deleteAtBeginDLL(head);
            }
            else
            {
                head = deleteAtPositionDLL(head, position);
            }
            break;
        case 7:
            if (head == NULL)
            {
                printf("DLL is empty.\n\n");
            }
            else
            {
                printForwardsDLL(head);
            }
            break;
        case 8:
            if (head == NULL)
            {
                printf("DLL is empty.\n\n");
            }
            else
            {
                printBackwardsDLL(head);
            }
            break;
        default:
            printf("Incorrect input, please try again.\n\n");
            break;
        }
    }
    return 0;
}