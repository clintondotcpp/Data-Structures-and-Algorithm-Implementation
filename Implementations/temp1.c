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

// Function to reverse the linked list iteratively
void reverseListIterative(struct Node **head)
{
    struct Node *prev = NULL;     // Initialize previous node to NULL
    struct Node *current = *head; // Start with the head node
    struct Node *next = NULL;     // Initialize next node to NULL
    while (current != NULL)
    {                         // Traverse the list
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the previous node one step forward
        current = next;       // Move the current node one step forward
    }
    *head = prev; // Update the head to the new first node
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

    reverseListIterative(&head); // Reverse the list iteratively

    printf("Reversed Linked list (Iterative): ");
    displayList(head); // Display the reversed list

    return 0;
}
