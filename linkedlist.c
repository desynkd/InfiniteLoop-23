#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0

typedef struct Nodes
{
    int data;
    struct Nodes* next;
}Node;

Node *CreateList(int Size);
void DisplayList(Node *head);
void FreeList(Node *head);

int main()
{
    Node *start = NULL;
    int arrlen;

    printf("What is the size of int array? : ");
    scanf("%d", &arrlen);

    start = CreateList(arrlen);
    DisplayList(start);
    FreeList(start);
}

Node *CreateList(int Size)
{
    int n;
    Node *head, *current;

    for (n=0; n < Size; n++ )
    {
        if (n==0)
        {
            head = (Node*)malloc(sizeof(Node));
            current = head;
        }
        else
        {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
        }

        printf("Enter Number %d\n", n+1);
        scanf("%d", &current->data);
    }

    current->next = NULL;
    return head;
}

void DisplayList(Node *head)
{
    int n = 1;
    Node *current;

    current = head;
    while (current->next != NULL)
    {
        printf("Number %d : %d\n", n++, current->data);
        current = current->next;
    }
    if(current != NULL){
        printf("Number %d : %d\n", n++, current->data);
    }
}

void FreeList(Node *head)
{
    Node *current, *front;

    current = head;
    while(current != NULL)
    {
        front = current->next;
        free(current);
        current = front;
    }
}
