#include <stdio.h>
#include <stdlib.h>

// Linked list to insert node at nth position

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtBeginning(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertNodenthPosition(struct Node **head, int data, int n)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = NULL;
    if (n = 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node *temp2 = *head;

    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insertNodeAtBeginning(&head, 5);
    insertNodenthPosition(&head, 11, 1);
    insertNodenthPosition(&head, 11, 2);
    insertNodenthPosition(&head, 25, 3);
    insertNodenthPosition(&head, 91, 4);
    displayList(head);
}