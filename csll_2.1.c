#include <stdio.h>
#include <stdlib.h>

// Definition of CSLL Node
struct CSLLNode {
    int data;
    struct CSLLNode* next;
};

// Create new node
struct CSLLNode* createNodeCSLL(int data) {
    struct CSLLNode* newNode = (struct CSLLNode*)malloc(sizeof(struct CSLLNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEndCSLL(struct CSLLNode** head, int data) {
    struct CSLLNode* newNode = createNodeCSLL(data);
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

// Insert at beginning
void insertBeginningCSLL(struct CSLLNode** head, int data) {
    struct CSLLNode* newNode = createNodeCSLL(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CSLLNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Insert at position
void insertAtPositionCSLL(struct CSLLNode** head, int data, int pos) {
    struct CSLLNode* newNode = createNodeCSLL(data);

    if (*head == NULL && pos == 1) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    if (pos == 1) {
        insertBeginningCSLL(head, data);
        return;
    }

    struct CSLLNode* temp = *head;
    int count = 1;
    while (count < pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void displayCSLL(struct CSLLNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CSLLNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Count nodes
int countNodesCSLL(struct CSLLNode* head) {
    if (head == NULL) return 0;
    int count = 0;
    struct CSLLNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Search for element and return position(s)
void searchCSLL(struct CSLLNode* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CSLLNode* temp = head;
    int pos = 1, found = 0;
    do {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        printf("Key %d not found in list\n", key);
}

// Delete node by value
void deleteNodeCSLL(struct CSLLNode** head, int key) {
    if (*head == NULL) return;

    struct CSLLNode *curr = *head, *prev = NULL;

    // If head to be deleted
    if (curr->data == key) {
        if (curr->next == curr) {
            free(curr);
            *head = NULL;
            return;
        }

        while (curr->next != *head)
            curr = curr->next;

        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    prev = *head;
    curr = (*head)->next;

    while (curr != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == *head) {
        printf("Key not found\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Main function for quick testing
int main() {
    struct CSLLNode* head = NULL;

    insertEndCSLL(&head, 10);
    insertEndCSLL(&head, 20);
    insertEndCSLL(&head, 30);
    displayCSLL(head);

    insertBeginningCSLL(&head, 5);
    displayCSLL(head);

    insertAtPositionCSLL(&head, 25, 4);
    displayCSLL(head);

    printf("Total nodes: %d\n", countNodesCSLL(head));
    searchCSLL(head, 20);
    searchCSLL(head, 40);

    deleteNodeCSLL(&head, 5);
    displayCSLL(head);

    deleteNodeCSLL(&head, 30);
    displayCSLL(head);

    deleteNodeCSLL(&head, 100); // Non-existent
    displayCSLL(head);

    return 0;
}
