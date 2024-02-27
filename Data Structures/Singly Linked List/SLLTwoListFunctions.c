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
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = 0;
    temp->next = NULL;
    return temp;
}

//------ Adding a node in a SLL at the end -------
NODE insertAtEndSLL(NODE head, int data)
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

//------- Singly Linked List Menu ------
void printMenuSLL()
{
    printf("1. Add element in SLL1");
    printf("\n2. Add element in SLL2");
    printf("\n3. Concatenate both SLLs into SLL1");
    printf("\n4. Make a Union of both SLLs into SLL1");
    printf("\n5. Make an intersection of both SLLs into SLL1");
    printf("\n6. Merge both SLLs into SLL1");
    printf("\n7. Print all Lists");
    printf("\n0. Exit the program");
    printf("\n\nEnter your choice : ");
}

//======= (MAIN Function) =======
int main()
{
    NODE head = NULL;
    NODE SLL2 = NULL;

    NODE concatenatedSLL = NULL;
    NODE unionSLL = NULL;
    NODE intersectionSLL = NULL;
    NODE mergedSLL = NULL;

    int userChoice = 1;
    int data = 0;
    int position = 0;
    while (userChoice)
    {
        printMenuSLL();
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 0:
            return 0;

        case 1:
            printf("Enter input data : ");
            scanf("%d", &data);
            head = insertAtEndSLL(head, data);
            printf("\n");
            break;
        case 3:

            printf("Enter input data : ");
            scanf("%d", &data);
            printf("Enter position to insert data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = insertAtBeginSLL(head, data);
            }
            else
            {
                head = insertAtPositionSLL(head, data, position);
            }
            printf("\n");
            break;
        case 4:
            head = deleteAtBeginSLL(head);
            break;
        case 5:
            head = deleteAtEndSLL(head);
            break;
        case 6:
            printf("Enter position to delete data : ");
            scanf("%d", &position);
            if (position == 1)
            {
                head = deleteAtBeginSLL(head);
            }
            else
            {
                head = deleteAtPositionSLL(head, position);
            }
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