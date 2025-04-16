// Circular Doubly Linked List (CDLL): Delete from End

// How It Works

// Since CDLL has prev pointers and the head->prev is always the 
// last node, this operation is constant-time.

// You can access:
//     ->  last = head->prev
//     ->  secondLast = last->prev
//     ->  Update their pointers to remove last

// void deleteFromEndCDLL(struct CDLLNode** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     // Only one node
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//         return;
//     }

//     struct CDLLNode* last = (*head)->prev;
//     struct CDLLNode* secondLast = last->prev;

//     secondLast->next = *head;
//     (*head)->prev = secondLast;

//     free(last);
// }

// Before :
// head
// ↓
// ┌────────────┐ ⇄ ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘
//      ↑                             ↓
//      └─────────────────────────────┘

// After:
// head
//   ↓
// ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │
// └────────────┘   └────────────┘
//        ↑             ↓
//        └─────────────┘

