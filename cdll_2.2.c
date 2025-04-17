#include <stdio.h>
#include <stdlib.h>

// Definition of CDLL Node
struct CDLLNode {
    int data;
    struct CDLLNode* next;
    struct CDLLNode* prev;
};

// Create a new node
struct CDLLNode* createNodeCDLL(int data) {
    struct CDLLNode* newNode = (struct CDLLNode*)malloc(sizeof(struct CDLLNode));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEndCDLL(struct CDLLNode** head, int data) {
    struct CDLLNode* newNode = createNodeCDLL(data);

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

// Insert at beginning
void insertBeginningCDLL(struct CDLLNode** head, int data) {
    insertEndCDLL(head, data);
    *head = (*head)->prev; // Move head back to new node
}

// Insert at position
void insertAtPositionCDLL(struct CDLLNode** head, int data, int pos) {
    int count = 1;
    struct CDLLNode* temp = *head;

    if (*head == NULL && pos == 1) {
        insertBeginningCDLL(head, data);
        return;
    }

    if (pos == 1) {
        insertBeginningCDLL(head, data);
        return;
    }

    struct CDLLNode* newNode = createNodeCDLL(data);
    while (count < pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    struct CDLLNode* after = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = after;
    after->prev = newNode;
}

// Display Forward
void displayForwardCDLL(struct CDLLNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CDLLNode* temp = head;
    printf("Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Display Reverse
void displayReverseCDLL(struct CDLLNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CDLLNode* tail = head->prev;
    struct CDLLNode* temp = tail;
    printf("Reverse: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("(tail)\n");
}

// Count nodes
int countNodesCDLL(struct CDLLNode* head) {
    if (head == NULL) return 0;
    int count = 0;
    struct CDLLNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Search with position
void searchCDLL(struct CDLLNode* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int pos = 1, found = 0;
    struct CDLLNode* temp = head;
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
void deleteNodeCDLL(struct CDLLNode** head, int key) {
    if (*head == NULL) return;

    struct CDLLNode* curr = *head;
    struct CDLLNode* temp = NULL;

    // Search for node with key
    do {
        if (curr->data == key)
            break;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != key) {
        printf("Key %d not found\n", key);
        return;
    }

    // Single node case
    if (curr->next == curr && curr->prev == curr) {
        free(curr);
        *head = NULL;
        return;
    }

    if (curr == *head)
        *head = curr->next;

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}

// Driver program to test CDLL
int main() {
    struct CDLLNode* head = NULL;

    insertEndCDLL(&head, 10);
    insertEndCDLL(&head, 20);
    insertEndCDLL(&head, 30);
    displayForwardCDLL(head);
    displayReverseCDLL(head);

    insertBeginningCDLL(&head, 5);
    displayForwardCDLL(head);

    insertAtPositionCDLL(&head, 25, 4);
    displayForwardCDLL(head);

    printf("Total nodes: %d\n", countNodesCDLL(head));
    searchCDLL(head, 20);
    searchCDLL(head, 50);

    deleteNodeCDLL(&head, 5);
    displayForwardCDLL(head);

    deleteNodeCDLL(&head, 30);
    displayForwardCDLL(head);

    deleteNodeCDLL(&head, 100); // Non-existent
    displayForwardCDLL(head);

    return 0;
}
