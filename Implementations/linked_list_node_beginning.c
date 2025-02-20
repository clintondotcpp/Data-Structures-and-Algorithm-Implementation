#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    temp->data = data;                                              // Set the data of the new node
    temp->next = NULL;                                              // Initialize the next pointer to NULL
    return temp;                                                    // Return the new node
}

// Function to insert a node at the beginning of the link list
void insertNodeAtBeginning(struct Node **head, int data)
{
    struct Node *temp = createNode(data); // Create a new node with given data
    temp->next = *head;                   // point the next of the new node to the current head
    *head = temp;                         // Make the new node as the head
}

void displayList(struct Node *head)
{
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)      // Traverse until the end of the list
    {
        printf("%d -> ", temp->data); // print the data of each node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n"); // Print NULL at the end
}

int main()
{
    struct Node *head = NULL; // Initialize an empty list
    insertNodeAtBeginning(&head, 5);
    printf("Linked list: ");
    displayList(head);
}