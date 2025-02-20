#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNodeAtBeginning(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertNodeNthPos(struct Node **head, int data, int position)
{
    struct Node *temp = createNode(data);
    temp->data = data;
    temp->next = NULL;
    if (position == 1)
    {
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

void deleteNodeKey(struct Node **head, int key)
{
    struct Node *temp = *head; // Temporary pointer to traverse the list
    struct Node *prev = NULL;  // Pointer to keep track of the previous node

    // Let's check if the head node holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next; // change the head
        free(temp);
        return;
    }

    // Let's search for the key to be deleted

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // if the key was not present in the list
    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void Print(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d - > ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insertNodeAtBeginning(&head, 101);
    insertNodeNthPos(&head, 21, 2);
    insertNodeNthPos(&head, 13, 3);
    insertNodeNthPos(&head, 349, 4);
    insertNodeNthPos(&head, 213, 5);
    deleteNodeKey(&head, 21);
    deleteNodeKey(&head, 213);
    Print(&head);
}