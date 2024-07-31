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

// Function to reverse the linked list recursively
void reverseListRecursive(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return; // Base case: empty list or single node list
    }
    struct Node *rest = (*head)->next; // Point to the rest of the list
    reverseListRecursive(&rest);       // Recursively reverse the rest of the list
    (*head)->next->next = *head;       // Make the next node point to the current node
    (*head)->next = NULL;              // Set the current node's next to NULL
    *head = rest;                      // Update the head to the new first node
}

int main()
{
    struct Node *head = NULL; // Initialize an empty list

    // Insert nodes into the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    printf("Original Linked list: ");
    displayList(head); // Display the list

    reverseListRecursive(&head); // Reverse the list recursively

    printf("Reversed Linked list (Recursive): ");
    displayList(head); // Display the reversed list

    return 0;
}
