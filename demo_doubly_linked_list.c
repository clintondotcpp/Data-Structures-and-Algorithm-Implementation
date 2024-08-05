#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
struct Node
{
    int data;          // Data part of the node
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
};

// Function prototypes
struct Node *createNode(int data);
void insertAtBeginning(struct Node **head, int data);
void insertAtEnd(struct Node **head, int data);
void insertAfter(struct Node *prevNode, int data);
void deleteNode(struct Node **head, struct Node *del);
void deleteNodeByKey(struct Node **head, int key);
void deleteNodeByPosition(struct Node **head, int position);
struct Node *search(struct Node *head, int key);
void updateNode(struct Node *head, int oldData, int newData);
void displayForward(struct Node *head);
void displayBackward(struct Node *head);

int main()
{
    struct Node *head = NULL; // Initialize the head of the list

    // Inserting elements into the doubly linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Doubly linked list after inserting elements at the end: ");
    displayForward(head); // Display the list

    // Inserting an element at the beginning
    insertAtBeginning(&head, 5);
    printf("Doubly linked list after inserting element at the beginning: ");
    displayForward(head); // Display the list

    // Inserting an element after a given node
    insertAfter(head->next, 15); // Insert 15 after the second node
    printf("Doubly linked list after inserting element after a given node: ");
    displayForward(head); // Display the list

    // Deleting a node by reference
    deleteNode(&head, head->next->next); // Delete the node with value 15
    printf("Doubly linked list after deleting a node by reference: ");
    displayForward(head); // Display the list

    // Deleting a node by key
    deleteNodeByKey(&head, 20); // Delete the node with value 20
    printf("Doubly linked list after deleting a node by key: ");
    displayForward(head); // Display the list

    // Deleting a node by position
    deleteNodeByPosition(&head, 2); // Delete the third node (position starts from 0)
    printf("Doubly linked list after deleting a node by position: ");
    displayForward(head); // Display the list

    // Searching for an element in the list
    struct Node *foundNode = search(head, 30);
    if (foundNode != NULL)
    {
        printf("Element 30 found in the list.\n");
    }
    else
    {
        printf("Element 30 not found in the list.\n");
    }

    // Updating a node's value
    updateNode(head, 10, 25); // Update node with value 10 to 25
    printf("Doubly linked list after updating a node's value: ");
    displayForward(head); // Display the list

    // Display the list backward
    printf("Doubly linked list displayed backward: ");
    displayBackward(head); // Display the list backward

    return 0;
}

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;                                              // Set the data of the new node
    newNode->prev = NULL;                                              // Initialize the previous pointer to NULL
    newNode->next = NULL;                                              // Initialize the next pointer to NULL
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data); // Create a new node
    newNode->next = *head;                   // Make the new node's next point to the current head
    if (*head != NULL)
    {
        (*head)->prev = newNode; // Make the current head's previous point to the new node
    }
    *head = newNode; // Update the head to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data); // Create a new node
    if (*head == NULL)
    {
        *head = newNode; // If the list is empty, make the new node the head
        return;
    }
    struct Node *temp = *head; // Temporary pointer to traverse the list
    while (temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Make the last node's next point to the new node
    newNode->prev = temp; // Make the new node's previous point to the last node
}

// Function to insert a node after a given node
void insertAfter(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node *newNode = createNode(data); // Create a new node
    newNode->next = prevNode->next;          // Make the new node's next point to the previous node's next
    prevNode->next = newNode;                // Make the previous node's next point to the new node
    newNode->prev = prevNode;                // Make the new node's previous point to the previous node
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode; // Make the new node's next's previous point to the new node
    }
}

// Function to delete a node by reference
void deleteNode(struct Node **head, struct Node *del)
{
    if (*head == NULL || del == NULL)
    {
        return; // If the list is empty or the node to be deleted is NULL, return
    }
    if (*head == del)
    {
        *head = del->next; // If the node to be deleted is the head, update the head
    }
    if (del->next != NULL)
    {
        del->next->prev = del->prev; // Update the next node's previous pointer
    }
    if (del->prev != NULL)
    {
        del->prev->next = del->next; // Update the previous node's next pointer
    }
    free(del); // Free the memory of the node to be deleted
}

// Function to delete a node by key
void deleteNodeByKey(struct Node **head, int key)
{
    struct Node *temp = *head; // Temporary pointer to traverse the list
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next; // Traverse to the node with the given key
    }
    if (temp == NULL)
    {
        printf("Element with key %d not found in the list.\n", key);
        return; // If the node with the given key is not found, return
    }
    deleteNode(head, temp); // Delete the node
}

// Function to delete a node by position
void deleteNodeByPosition(struct Node **head, int position)
{
    if (*head == NULL || position < 0)
    {
        printf("Invalid position.\n");
        return; // If the list is empty or the position is invalid, return
    }
    struct Node *temp = *head; // Temporary pointer to traverse the list
    for (int i = 0; temp != NULL && i < position; i++)
    {
        temp = temp->next; // Traverse to the node at the given position
    }
    if (temp == NULL)
    {
        printf("Position %d not found in the list.\n", position);
        return; // If the position is not found, return
    }
    deleteNode(head, temp); // Delete the node
}

// Function to search for an element in the list
struct Node *search(struct Node *head, int key)
{
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp; // Return the node if the key is found
        }
        temp = temp->next; // Move to the next node
    }
    return NULL; // Return NULL if the key is not found
}

// Function to update a node's value
void updateNode(struct Node *head, int oldData, int newData)
{
    struct Node *temp = search(head, oldData); // Search for the node with the old data
    if (temp != NULL)
    {
        temp->data = newData; // Update the node's data if found
    }
    else
    {
        printf("Element with value %d not found in the list.\n", oldData);
    }
}

// Function to display the elements of the list in forward direction
void displayForward(struct Node *head)
{
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Print the data of each node
        temp = temp->next;         // Move to the next node
    }
    printf("\n");
}

// Function to display the elements of the list in backward direction
void displayBackward(struct Node *head)
{
    if (head == NULL)
    {
        return; // If the list is empty, return
    }
    struct Node *temp = head; // Temporary pointer to traverse the list
    while (temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Print the data of each node
        temp = temp->prev;         // Move to the previous node
    }
    printf("\n");
}
