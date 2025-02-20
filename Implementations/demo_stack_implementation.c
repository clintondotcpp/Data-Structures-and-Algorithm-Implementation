#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Define the maximum size of the stack

// Define the structure for a stack
struct Stack
{
    int items[MAX_SIZE]; // Array to store stack elements
    int top;             // Index of the top element
};

// Function prototypes
struct Stack *createStack();
bool isFull(struct Stack *stack);
bool isEmpty(struct Stack *stack);
void push(struct Stack *stack, int item);
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
    stack->top = -1;                                                    // Initialize the top index to -1 (empty stack)
    return stack;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1; // Return true if top is at the last index
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == -1; // Return true if top is -1 (empty stack)
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    stack->items[++stack->top] = item; // Increment top and add item to the stack
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop element.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--]; // Return the top element and decrement top
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top]; // Return the top element without removing it
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
