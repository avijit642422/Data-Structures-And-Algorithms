//sll operation
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// 1. Creation
void create() {
    struct Node *first, *second, *third;

    first = ( struct Node *)malloc(sizeof(struct Node));
    second = ( struct Node *)malloc(sizeof(struct Node));
    third =( struct Node *) malloc(sizeof(struct Node));

    if (first == NULL || second == NULL || third == NULL) {
        printf("Memory Allocation Failed\n");
        free(first);
        free(second);
        free(third);
        return;
    }

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;
}

// 2. Traversal
void traversal() {
    struct Node *temp;

    temp = head;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
  printf("\n");
}

// 3. Insert at Beginning
void insertBeginning(int data) {
    struct Node *newNode;

    newNode =( struct Node *) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// 4. Insert at End
void insertEnd(int data) {
    struct Node *newNode;
    struct Node *temp;

    newNode =( struct Node *) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// 5. Insert at Any Position
void insertPosition(int data, int pos) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (pos < 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertBeginning(data);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    newNode =( struct Node *) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;

    newNode->next = temp->next;
    temp->next = newNode;
}

// 6. Delete at Beginning
void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Empty, Can't Delete\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

// 7. Delete at End
void deleteEnd() {
    struct Node *temp;
    struct Node *prev;

    if (head == NULL) {
        printf("Empty, Can't Delete\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted Successfully\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);
}

// 8. Delete at Any Position
void deletePosition(int pos) {
    struct Node *temp;
    struct Node *prev;
    int i;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = head;
    prev = NULL;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// 9. Searching (Linear Search)
void search(int key) {
    struct Node *temp;
    int position = 1;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    temp = head;

    while (temp != NULL) {

        if (temp->data == key) {
            printf("Element Found at Position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element Not Found\n");
}

// 10. Reverse Linked List
void reverse(){
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
int main(){
    create();
    traversal();
    insertBeginning(5);
    traversal();
    insertEnd(40);
    traversal();
    insertPosition(25,3);
    traversal();
    deleteBeginning();
    traversal();
    deleteEnd();
    traversal();
    deletePosition(2);
    traversal();
    search(30);
    traversal();
    reverse();
    traversal();
    return 0;
}