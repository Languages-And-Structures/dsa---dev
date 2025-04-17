#include <stdio.h>
#include <stdlib.h>

struct CSLLNode {
    int data;
    struct CSLLNode* next;
};

// Utility
struct CSLLNode* createNode(int data) {
    struct CSLLNode* newNode = (struct CSLLNode*)malloc(sizeof(struct CSLLNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct CSLLNode** head, int data) {
    struct CSLLNode* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CSLLNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Insert at position
void insertAtPosition(struct CSLLNode** head, int data, int pos) {
    struct CSLLNode* newNode = createNode(data);
    if (pos <= 1 || *head == NULL) {
        if (*head == NULL) {
            newNode->next = newNode;
            *head = newNode;
        } else {
            struct CSLLNode* temp = *head;
            while (temp->next != *head) temp = temp->next;
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        return;
    }
    struct CSLLNode* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Search
void search(struct CSLLNode* head, int target) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    int pos = 1;
    struct CSLLNode* temp = head;
    do {
        if (temp->data == target) {
            printf("Element %d found at position %d\n", target, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found\n", target);
}

// Delete by value
void deleteByValue(struct CSLLNode** head, int val) {
    if (!*head) return;

    struct CSLLNode *curr = *head, *prev = NULL;
    do {
        if (curr->data == val) break;
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != val) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (curr == *head) {
        struct CSLLNode* last = *head;
        while (last->next != *head) last = last->next;
        if (last == *head) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
        }
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

// Display
void display(struct CSLLNode* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct CSLLNode* temp = head;
    printf("CSLL: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Menu
int main() {
    struct CSLLNode* head = NULL;
    int choice, data, pos;

    do {
        printf("\n1. Insert End\n2. Insert at Position\n3. Delete by Value\n4. Search\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &data);
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
                display(head);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
