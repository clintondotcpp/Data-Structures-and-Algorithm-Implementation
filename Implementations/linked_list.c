#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *temp = *head;
    temp->data = data;
    temp->next = NULL;
    if (*head = NULL)
    {
        *head = temp;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *head;
    *head = temp;
}

void insertNodeAtNthPos(struct Node **head, int data, int position)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = NULL;
    if (position == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node *temp2 = *head;
    for (int i = 0; i < position - 2; i++)
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
    insertAtEnd(&head, 1);
    insertNodeAtNthPos(&head, 522, 1);
    insertNodeAtNthPos(&head, 111, 2);
    insertNodeAtNthPos(&head, 13, 3);
    insertNodeAtNthPos(&head, 22, 4);
    insertNodeAtNthPos(&head, 15, 5);
    displayList(head);
}