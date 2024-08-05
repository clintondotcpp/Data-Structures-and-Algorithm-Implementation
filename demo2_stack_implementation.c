#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

// Define the structure for a stack
struct Stack
{
    struct Node *top; // Pointer to the top element of the stack
};

// Function prototypes
struct Stack *createStack();
bool isEmpty(struct Stack *stack);
void push(struct Stack *stack, int data);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
void display(struct Stack *stack);

int main()
{
    struct Stack *stack = createStack(); // Create a stack

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("Stack after pushing elements: ");
    display(stack); // Display the stack

    // Pop an element from the stack
    printf("Popped element: %d\n", pop(stack));
    printf("Stack after popping an element: ");
    display(stack); // Display the stack

    // Peek at the top element
    printf("Top element: %d\n", peek(stack));

    return 0;
}

// Function to create a stack
struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack)); // Allocate memory for a stack
    stack->top = NULL;                                                  // Initialize the top pointer to NULL (empty stack)
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == NULL; // Return true if top is NULL (empty stack)
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;                                              // Set the data of the new node
    newNode->next = stack->top;                                        // Point the new node's next to the current top
    stack->top = newNode;                                              // Update the top pointer to the new node
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop element.\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = stack->top; // Temporary pointer to the top element
    int poppedData = temp->data;    // Get the data of the top element
    stack->top = stack->top->next;  // Update the top pointer to the next element
    free(temp);                     // Free the memory of the popped element
    return poppedData;              // Return the popped data
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data; // Return the data of the top element
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
    struct Node *temp = stack->top; // Temporary pointer to traverse the stack
    while (temp != NULL)
    {                              // Traverse until the end of the stack
        printf("%d ", temp->data); // Print the data of each node
        temp = temp->next;         // Move to the next node
    }
    printf("\n");
}
