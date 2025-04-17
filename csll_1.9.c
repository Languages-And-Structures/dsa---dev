// Insertion at Position in Circular Singly Linked List (CSLL)

// void insertAtPositionCSLL(struct CSLLNode** head, int data, int pos) {
//     struct CSLLNode* newNode = createNodeCSLL(data);

//     if (*head == NULL && pos == 1) {
//         newNode->next = newNode;
//         *head = newNode;
//         return;
//     }

//     if (pos == 1) {
//         struct CSLLNode* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         newNode->next = *head;
//         temp->next = newNode;
//         *head = newNode;
//         return;
//     }

//     struct CSLLNode* temp = *head;
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
//     temp->next = newNode;
// }

// List: 10 → 20 → 30 → (head)
// Insert: 15 at position 2
//     ->  temp = head = 10
//     ->  count = 1 < 2 - 1 → no
//     ->  newNode = 15
//     ->  newNode->next = temp->next = 20
//     ->  temp->next = newNode
// Updated list: 10 → 15 → 20 → 30 → (head)

// Memory Diagram

// [10] → [15] → [20] → [30]
//  ↑                         ↓
//  └────────────────────────┘























