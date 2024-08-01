#include <stdio.h>
#include <stdlib.h>

// Code to insert a node at the end of the linked list

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNodeAtBeginning(struct Node **head, int data)
{
    struct Node *temp = createNode(data); // create node
    temp->data = data;                    // set data part to data
    temp->next = *head;                   // point the link part to head
    *head = temp;                         // assign temp to head so
}

void insertNodeAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head; // temporary pointer to traverse the list
    while (temp->next != NULL)
    { // We traverse the list by making sure the next node exists
        temp = temp->next;
    }
    temp->next = newNode; // We point the next part of temp to the newly created node
}

void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp == NULL && temp->data == key)
    {                       // If the head is the only node
        *head = temp->next; // set head head to the new node
        free(temp);         // free the deleted node
        return;
    }

    // do a search for the key
    while (temp != NULL && temp->data != key)
    {
        prev = temp->next;
        temp = *head;
    }

    // If the key was not present in the list
    if (temp == NULL)
        return;

    prev->next = temp->next; // Unlink the node from the linked list
    free(temp);
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
    insertNodeAtEnd(&head, 11);
    insertNodeAtEnd(&head, 71);
    insertNodeAtEnd(&head, 93);
    displayList(head);
}