#include <stdio.h>
#include <stdlib.h>

struct CDLLNode {
    int data;
    struct CDLLNode* next;
    struct CDLLNode* prev;
};

// Create a new node
struct CDLLNode* createNode(int data) {
    struct CDLLNode* newNode = (struct CDLLNode*)malloc(sizeof(struct CDLLNode));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct CDLLNode** head, int data) {
    struct CDLLNode* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }
    struct CDLLNode* tail = (*head)->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Insert at position
void insertAtPosition(struct CDLLNode** head, int data, int pos) {
    struct CDLLNode* newNode = createNode(data);
    if (*head == NULL || pos <= 1) {
        insertEnd(head, data);
        *head = (*head)->prev; // Insert at head
        return;
    }

    struct CDLLNode* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
        temp = temp->next;

    struct CDLLNode* nextNode = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

// Delete by value
void deleteByValue(struct CDLLNode** head, int value) {
    if (*head == NULL) return;

    struct CDLLNode *curr = *head, *toDelete = NULL;

    do {
        if (curr->data == value) {
            toDelete = curr;
            break;
        }
        curr = curr->next;
    } while (curr != *head);

    if (toDelete == NULL) {
        printf("Value %d not found\n", value);
        return;
    }

    if (toDelete->next == toDelete) {
        free(toDelete);
        *head = NULL;
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        if (toDelete == *head)
            *head = toDelete->next;
        free(toDelete);
    }
}

// Search
void search(struct CDLLNode* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int pos = 1;
    struct CDLLNode* temp = head;
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Value %d not found\n", value);
}

// Display forward
void displayForward(struct CDLLNode* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct CDLLNode* temp = head;
    printf("CDLL Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Display reverse
void displayReverse(struct CDLLNode* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct CDLLNode* temp = head->prev;
    printf("CDLL Reverse: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(tail)\n");
}

// Menu
int main() {
    struct CDLLNode* head = NULL;
    int choice, data, pos;

    do {
        printf("\n1. Insert End\n2. Insert at Position\n3. Delete by Value\n4. Search\n5. Display Forward\n6. Display Reverse\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(&head, data);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 5:
                displayForward(head);
                break;
            case 6:
                displayReverse(head);
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}
