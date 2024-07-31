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

// Function to delete all nodes with a given key
void deleteAllNodesWithKey(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Loop to delete nodes at the beginning with the given key
    while (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    // Loop to delete nodes beyond the head with the given key
    while (temp != NULL)
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in the remaining list
        if (temp == NULL)
            return;

        // Unlink the node from the list
        prev->next = temp->next;
        free(temp);

        // Update temp for next iteration
        temp = prev->next;
    }
}

// Function to delete a node at a given position
void deleteNodeAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
        return; // If the list is empty

    struct Node *temp = *head;

    // If head needs to be removed
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // If the position is more than the number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from the list
    free(temp->next);
    temp->next = next;
}

int main()
{
    struct Node *head = NULL; // Initialize an empty list

    // Insert nodes into the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 2);

    printf("Original Linked list: ");
    displayList(head); // Display the list

    deleteAllNodesWithKey(&head, 2); // Delete all nodes with data 2
    printf("Linked list after deleting all nodes with key 2: ");
    displayList(head); // Display the list

    deleteNodeAtPosition(&head, 1); // Delete node at position 1
    printf("Linked list after deleting node at position 1: ");
    displayList(head); // Display the list

    return 0;
}
