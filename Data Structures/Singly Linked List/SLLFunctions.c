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
    NODE addNode = createNode();
    addNode->data = data;
    addNode->next = head;
    head = addNode;
    return head;
}

//------ Adding a node in a SLL at the end -------
NODE insertAtEnd(NODE head, int data)
{
    NODE addNode = createNode();
    addNode->data = data;

    if (head == NULL)
    {
        head = addNode;
    }
    else
    {
        NODE lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = addNode;
    }
    return head;
}
//------ Adding a node in a SLL at the specified position -------
NODE insertAtPosition(NODE head, int data, int position)
{
    // Position cannot be 0 or less than 0.
    if (position <= 0)
    {
        printf("Please insert a position.\n\n");
        return head;
    }

    NODE current = head;
    NODE previous = NULL;
    int count = 0;

    // Loop to reach the position in the Linked List
    for (count = 0; count < (position - 1); count++)
    {
        // Leave the loop if position is longer than the list.
        if (current == NULL)
        {
            printf("Position does not exist, please try a lower value or print the list.\n\n");
            return head;
        }
        if (current != NULL)
        {
            previous = current;
            current = current->next;
        }
    }

    NODE addNode = createNode();
    addNode->data = data;

    addNode->next = current;
    previous->next = addNode;

    return head;
}
//------ Deleting a node in a SLL at the beginning ------
NODE deleteAtBegin(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete elements.\n\n");
        return NULL;
    }
    if (head -> next == NULL)
    {
        free (head);
        return NULL;
    }
    else
    {
        NODE deleteNode = head;
        head = head->next;
        free(deleteNode);
    }
    return head;
}

//------ Deleting a node in a SLL at the end -------
NODE deleteAtEnd(NODE head)
{
    NODE previous = NULL;
    NODE deleteNode = head;

    if (deleteNode == NULL)
    {
        printf("List is empty. Cannot delete elements.\n\n");
        return NULL;
    }
    if (deleteNode -> next == NULL)
    {
        free (deleteNode);
        return NULL;
    }

    while (deleteNode -> next != NULL)
    {
        previous = deleteNode;
        deleteNode = deleteNode -> next;
    }
    previous -> next = NULL;
    free (deleteNode);
    return head;
}

//------ Deleting a node in a SLL at the specified position -------
NODE deleteAtPosition(NODE head, int position)
{
    // Position cannot be 0 or less than 0.
    if (position <= 0)
    {
        printf("Please insert a position.\n\n");
        return head;
    }

    NODE current = head;
    NODE previous = NULL;
    int count = 0;

    // Loop to reach the position in the Linked List
    for (count = 0; count < (position - 1); count++)
    {
        // Leave the loop if position is longer than the list.
        if (current == NULL)
        {
            printf("Position does not exist, please try a lower value or print the list.\n\n");
            return head;
        }
        if (current != NULL)
        {
            previous = current;
            current = current->next;
        }
    }

    NODE deleteNode = current;
    previous->next = current->next;

    free(deleteNode);
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
    printf("NULL\n\n");
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
    int position = 0;
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
            printf("\n");
            break;
        case 2:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            printf("\n");
            break;
        case 3:

            printf("Enter input data : ");
            scanf("%d", &data);
            printf("Enter position to insert data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = insertAtBegin(head, data);
            }
            else
            {
                head = insertAtPosition(head, data, position);
            }
            printf("\n");
            break;
        case 4:
            head = deleteAtBegin(head);
            break;
        case 5:
            head = deleteAtEnd(head);
            break;
        case 6:
            printf("Enter position to delete data : ");
            head = deleteAtPosition(head, position);
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