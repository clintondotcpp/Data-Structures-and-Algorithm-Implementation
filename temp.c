#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;                                              // Set the data of the new node
    newNode->next = NULL;                                              // Initialize the next pointer to NULL
    return newNode;                                                    // Return the new node
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data); // Create a new node with given data
    newNode->next = *head;                   // Point the next of the new node to the current head
    *head = newNode;                         // Make the new node as the head
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data); // Create a new node with given data
    if (*head == NULL)
    {                    // If the linked list is empty
        *head = newNode; // Make the new node as the head
        return;
    }
    struct Node *temp = *head; // Temporary pointer to traverse the list
    while (temp->next != NULL)
    { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Point the next of the last node to the new node
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {                                 // Traverse until the end of the list
        printf("%d -> ", temp->data); // Print the data of each node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n"); // Print NULL at the end
}

// Function to delete a node with given data
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head; // Temporary pointer to traverse the list
    struct Node *prev = NULL;  // Pointer to keep track of the previous node

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next; // Change the head
        free(temp);         // Free the old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL)
        return;

    prev->next = temp->next; // Unlink the node from the linked list
    free(temp);              // Free the memory of the node
}

int main()
{
    struct Node *head = NULL; // Initialize an empty list

    // Insert nodes into the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);

    printf("Linked list: ");
    displayList(head); // Display the list

    deleteNode(&head, 2); // Delete a node with data 2

    printf("Linked list after deletion: ");
    displayList(head); // Display the list after deletion

    return 0;
}
