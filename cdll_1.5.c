// CDLL: Delete at Position

// Concept
//     ->  Traverse to desired position
//     ->  Adjust both prev and next links
//     ->  Free the node
// Special cases:
//     ->  Empty list
//     ->  Only one node
//     ->  Position = 1 → handled with deleteBeginningCDLL

// void deleteAtPositionCDLL(struct CDLLNode** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     if (pos == 1) {
//         deleteBeginningCDLL(head);
//         return;
//     }

//     struct CDLLNode* temp = *head;
//     int count = 1;

//     while (count < pos && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos) {
//         printf("Position out of bounds.\n");
//         return;
//     }

//     temp->prev->next = temp->next;
//     temp->next->prev = temp->prev;
//     free(temp);
// }

// Given: 10 ⇄ 99 ⇄ 20 ⇄ 30, delete at position 2

// Before
// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 99   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘  └────────────┘
//        ↑                                             ↓
//        └────────────────────←────────────────────────┘

// temp = 99
// Adjust:
//     ->  10->next = 20
//     ->  20->prev = 10

// After
// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘
//        ↑                         ↓
//        └────────────←────────────┘


