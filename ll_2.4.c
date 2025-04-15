#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// INSERT AT BEGINNING
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

// INSERT AT END
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

// INSERT AFTER A GIVEN NODE
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

// INSERT BEFORE A GIVEN NODE
void insertBefore(struct Node** head, struct Node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("Next node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;

    if (nextNode->prev != NULL)
        nextNode->prev->next = newNode;
    else
        *head = newNode;

    nextNode->prev = newNode;
}

// DELETE BY VALUE
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

// DELETE AT POSITION
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

// TRAVERSE FORWARD
void printForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// TRAVERSE BACKWARD
void printReverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// SEARCH A VALUE
int search(struct Node* head, int key) {
    int pos = 0;
    while (head != NULL) {
        if (head->data == key) {
            printf("Value %d found at position %d.\n", key, pos);
            return 1;
        }
        head = head->next;
        pos++;
    }
    printf("Value %d not found.\n", key);
    return 0;
}

// COUNT NODES
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// FREE LIST
void freeList(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// MAIN FUNCTION (SAMPLE USAGE)
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAfter(head->next, 15);          // after 10
    insertBefore(&head, head->next->next, 12); // before 15

    printForward(head);
    printReverse(head);

    deleteByValue(&head, 12);
    deleteAtPosition(&head, 0);

    printForward(head);

    search(head, 20);
    search(head, 99);

    printf("Total Nodes: %d\n", countNodes(head));

    freeList(&head);

    return 0;
}
