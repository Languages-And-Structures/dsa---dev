// Add a Menu-Drive
//     ->  Insert elements at beginning or end
//     ->  Insert after a value
//     ->  Delete by value or position
//     ->  Search, count, print
//     ->  Exit program

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfterValue(struct Node *head, int key, int data)
{
    struct Node *temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp)
    {
        printf("Key not found.\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;
    if (temp && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Value not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node **head, int pos)
{
    if (*head == NULL || pos < 0)
        return;
    struct Node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp || !temp->next)
        return;
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

int search(struct Node *head, int key)
{
    int i = 0;
    while (head)
    {
        if (head->data == key)
            return i;
        head = head->next;
        i++;
    }
    return -1;
}

int countNodes(struct Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void traverse(struct Node *head)
{
    printf("List: ");
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node **head)
{
    struct Node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, data, key, pos;

    while (1)
    {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert after Value\n4. Delete by Value\n");
        printf("5. Delete at Position\n6. Search\n7. Count\n8. Traverse\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Insert after which value? ");
            scanf("%d", &key);
            printf("Enter new data: ");
            scanf("%d", &data);
            insertAfterValue(head, key, data);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            break;
        case 5:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        case 6:
            printf("Enter value to search: ");
            scanf("%d", &data);
            pos = search(head, data);
            if (pos >= 0)
                printf("Found at position %d\n", pos);
            else
                printf("Not found.\n");
            break;
        case 7:
            printf("Node count: %d\n", countNodes(head));
            break;
        case 8:
            traverse(head);
            break;
        case 9:
            freeList(&head);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
