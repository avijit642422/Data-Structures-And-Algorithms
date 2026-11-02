//cll operation
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create Circular Linked List
void create()
{
    struct Node *first, *second, *third;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head = first;

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = head;
}

// Traversal
void traversal()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}

// Insertion at Beginning
void insertBeginning(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insertion at End
void insertEnd(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Deletion at Beginning
void deleteBeginning()
{
    struct Node *temp;
    struct Node *deleteNode;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    deleteNode = head;
    head = head->next;
    temp->next = head;

    free(deleteNode);
}

// Deletion at End
void deleteEnd()
{
    struct Node *temp;
    struct Node *prev = NULL;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

    free(temp);
}

// Main Function
int main()
{
    create();
    traversal();

    insertBeginning(5);
    traversal();

    insertEnd(40);
    traversal();

    deleteBeginning();
    traversal();

    deleteEnd();
    traversal();

    return 0;
}

