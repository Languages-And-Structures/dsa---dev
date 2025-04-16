// Circular Doubly Linked List (CDLL): Insert at Position

// Concept
//     ->  Here, you use forward traversal just like CSLL, but update both 
//         next and prev pointers.
//     ->  For position:
//         ->  Traverse to position - 1
//         ->  Rewire both directions

// void insertAtPositionCDLL(struct CDLLNode** head, int data, int pos) {
//     struct CDLLNode* newNode = (struct CDLLNode*)malloc(sizeof(struct CDLLNode));
//     newNode->data = data;

//     if (pos < 1) {
//         printf("Invalid position.\n");
//         return;
//     }

//     if (pos == 1) {
//         insertAtBeginningCDLL(head, data);
//         return;
//     }

//     struct CDLLNode* temp = *head;
//     int count = 1;

//     while (count < pos - 1 && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos - 1) {
//         printf("Position out of bounds.\n");
//         return;
//     }

//     newNode->next = temp->next;
//     newNode->prev = temp;
//     temp->next->prev = newNode;
//     temp->next = newNode;
// }

// Operation: Insert at Position 2
// Given CDLL:

// 10 ⇄ 20 ⇄ 30 ⇄ (back to head)
// We insert 99 at position 2 (between 10 and 20).

// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘
//        ↑                         ↓
//        └──────────────←─────────┘

// After Allocating and Finding Position
// ->  temp = head
// ->  Move to position 1 (temp = 10)

// Insertion Rewiring
// ->  newNode->next    = temp->next → 99->next = 20
// ->  newNode->prev    = temp → 99->prev       = 10
// ->  temp->next->prev = newNode → 20->prev    = 99
// ->  temp->next       = newNode → 10->next    = 99

// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 99   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘  └────────────┘
//        ↑                                             ↓
//        └────────────────────←────────────────────────┘

