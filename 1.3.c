#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert after a given value
void insertAfterValue(struct Node *head, int key, int data)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value %d not found.\n", key);
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node by value
void deleteByValue(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Delete node by position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL || position < 0)
        return;

    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Traverse and print
void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search a value
int search(struct Node *head, int key)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == key)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

// Count nodes
int countNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Free memory
void freeList(struct Node **head)
{
    struct Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Driver code to test everything
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAfterValue(head, 10, 15);

    printf("Linked List: ");
    traverse(head);

    printf("Node count: %d\n", countNodes(head));

    int pos = search(head, 15);
    printf("Value 15 found at position: %d\n", pos);

    deleteByValue(&head, 10);
    printf("After deleting 10: ");
    traverse(head);

    deleteAtPosition(&head, 1);
    printf("After deleting at position 1: ");
    traverse(head);

    freeList(&head);
    printf("After freeing: ");
    traverse(head); // should print nothing

    return 0;
}


