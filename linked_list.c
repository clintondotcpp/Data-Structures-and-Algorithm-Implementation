#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct Node *temp = head;
    printf("The List is: ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int n, x;
    printf("How many elements do you want in the array");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter values for the array");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}