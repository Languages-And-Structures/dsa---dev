#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteByValue(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    if (temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL || pos < 0) return;

    struct Node* temp = *head;

    if (pos == 0) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    int i = 0;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void printForward(struct Node* head) {
    printf("List (forward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printReverse(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void search(struct Node* head, int key) {
    int pos = 0;
    while (head != NULL) {
        if (head->data == key) {
            printf("Found %d at position %d.\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("%d not found in the list.\n", key);
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void freeList(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Delete at Position\n");
        printf("5. Print Forward\n");
        printf("6. Print Reverse\n");
        printf("7. Search\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;

            case 4:
                printf("Enter position to delete (0-based): ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;

            case 5:
                printForward(head);
                break;

            case 6:
                printReverse(head);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 8:
                printf("Total nodes: %d\n", countNodes(head));
                break;

            case 9:
                freeList(&head);
                printf("List freed. Exiting.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
