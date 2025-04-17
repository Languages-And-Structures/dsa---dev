// Insertion at Position in Circular Doubly Linked List (CDLL)

// void insertAtPositionCDLL(struct CDLLNode** head, int data, int pos) {
//     struct CDLLNode* newNode = createNodeCDLL(data);

//     if (*head == NULL && pos == 1) {
//         newNode->next = newNode;
//         newNode->prev = newNode;
//         *head = newNode;
//         return;
//     }

//     if (pos == 1) {
//         struct CDLLNode* tail = (*head)->prev;

//         newNode->next = *head;
//         newNode->prev = tail;
//         tail->next = newNode;
//         (*head)->prev = newNode;
//         *head = newNode;
//         return;
//     }

//     struct CDLLNode* temp = *head;
//     int count = 1;

//     while (count < pos - 1 && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos - 1) {
//         printf("Invalid position.\n");
//         free(newNode);
//         return;
//     }

//     newNode->next = temp->next;
//     newNode->prev = temp;
//     temp->next->prev = newNode;
//     temp->next = newNode;
// }

// List: 10 ⇄ 20 ⇄ 30 ⇄ (head)
// Insert: 15 at position 2
//      ->  temp = 10
//      ->  newNode = 15
//      ->  newNode->next = 20, newNode->prev = 10
//      ->  20->prev = 15, 10->next = 15
// Result: 10 ⇄ 15 ⇄ 20 ⇄ 30 ⇄ (head)




