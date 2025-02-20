#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Define the maximum size of the array

// Function prototypes
void insert(int arr[], int *size, int element, int position);
void delete(int arr[], int *size, int position);
int search(int arr[], int size, int element);
void update(int arr[], int size, int position, int newElement);
void display(int arr[], int size);

int main()
{
    int arr[MAX_SIZE]; // Initialize the array
    int size = 0;      // Current size of the array

    // Inserting elements into the array
    insert(arr, &size, 10, 0); // Insert 10 at position 0
    insert(arr, &size, 20, 1); // Insert 20 at position 1
    insert(arr, &size, 30, 2); // Insert 30 at position 2
    insert(arr, &size, 40, 3); // Insert 40 at position 3

    printf("Array after insertion: ");
    display(arr, size); // Display the array

    // Deleting an element from the array
    delete (arr, &size, 1); // Delete element at position 1
    printf("Array after deletion: ");
    display(arr, size); // Display the array

    // Searching for an element in the array
    int index = search(arr, size, 30); // Search for element 30
    if (index != -1)
    {
        printf("Element 30 found at position %d\n", index);
    }
    else
    {
        printf("Element 30 not found\n");
    }

    // Updating an element in the array
    update(arr, size, 1, 25); // Update element at position 1 to 25
    printf("Array after update: ");
    display(arr, size); // Display the array

    return 0;
}

// Function to insert an element at a specified position
void insert(int arr[], int *size, int element, int position)
{
    if (*size >= MAX_SIZE)
    {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 0 || position > *size)
    {
        printf("Invalid position.\n");
        return;
    }
    // Shift elements to the right to create space for the new element
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element; // Insert the new element
    (*size)++;               // Increment the size of the array
}

// Function to delete an element from a specified position
void delete(int arr[], int *size, int position)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= *size)
    {
        printf("Invalid position.\n");
        return;
    }
    // Shift elements to the left to fill the space of the deleted element
    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Decrement the size of the array
}

// Function to search for an element in the array
int search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; // Return the position if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to update an element at a specified position
void update(int arr[], int size, int position, int newElement)
{
    if (position < 0 || position >= size)
    {
        printf("Invalid position.\n");
        return;
    }
    arr[position] = newElement; // Update the element at the specified position
}

// Function to display the elements of the array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
